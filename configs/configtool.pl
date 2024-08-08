#!/usr/bin/perl
## ###################################################################
##
## Copyright 2023-2024 NXP
##
## Redistribution and use in source and binary forms, with or without modification,
## are permitted provided that the following conditions are met:
##
## o Redistributions of source code must retain the above copyright notice, this list
##   of conditions and the following disclaimer.
##
## o Redistributions in binary form must reproduce the above copyright notice, this
##   list of conditions and the following disclaimer in the documentation and/or
##   other materials provided with the distribution.
##
## o Neither the name of the copyright holder nor the names of its
##   contributors may be used to endorse or promote products derived from this
##   software without specific prior written permission.
##
## THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
## ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
## WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
## DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
## ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
## (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
## LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
## ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
## (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
## SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
##
##
## ###################################################################

use strict;
use warnings;
use bigint;
use Getopt::Std;
use File::Basename;
use lib dirname (__FILE__);
use Data::Dumper;
use List::Util qw(first);

# Subroutines
sub load_config_files;
sub load_file;
sub do_substitutions;
sub generate_dox;
sub generate_mb;
sub generate_xport;
sub generate_scmi;
sub generate_lmm;
sub generate_dev;
sub generate_bctrl;
sub generate_board;
sub generate_trdc;
sub generate_test;
sub generate_make;
sub get_perms;
sub get_bctrl;
sub get_tests;
sub get_trdc_config;
sub get_trdc;
sub convert_trdc;
sub compress_data;
sub sapa;
sub param;
sub header;
sub footer;
sub banner;
sub copyright;
sub startstop;
sub error_line;
sub get_define;

my @protocols = ('base', 'pd', 'sys', 'perf', 'clk', 'sensor',
    'rst', 'volt', 'lmm', 'gpr', 'rtc', 'button', 'cpu', 'perlpi',
    'pin', 'daisy', 'ctrl', 'fault', 'fusa');
my @mbTypes = ('MU', 'LOOPBACK');
my @xportTypes = ('SMT');
	my @permTypes = ('none', 'get', 'notify', 'set', 'priv',
	    'exclusive', 'all');
my %makeInclude;
my %args;
my $log;

my $seenvid = 0;

# Parse command line
getopts('hi:l:o:v', \%args);
my $help = $args{h};
my $inputFile = $args{i};
my $logFile = $args{l};
my $outDir = $args{o};
my $verbose = $args{v};
my $config_name = 'CONFIG';

# Check for required arguments
if ($help || (not defined $inputFile) || (not defined $outDir))
{
    my $cmd = fileparse($0);

    print "Usage: $cmd [OPTIONS]...\n";
    print "Generate SM configuration files.\n\n";
    print "  -i  specify input file\n";
    print "  -o  specify output directory\n";
    print "  -l  specify optional log file\n";
    print "  -v  display processing steps\n";
    print "  -h  display this help and exit\n\n";
    print "The input configuration file is loaded, processed, and\n";
    print "configuration header files written to the output directory\n";
    exit;
}

# Support other cfg files
if (defined $inputFile)
{
	my $otherInputFile = $inputFile;
    $otherInputFile =~ s/configs/configs\/other/g;

	if (-e $otherInputFile)
	{
		$inputFile = $otherInputFile;
	}
}

# Open log file
if (defined $logFile)
{
    # Open file
    open $log, '>', $logFile
        or die "error: failure to open: $logFile, $!";
}

# Create output directory
if (! -e $outDir)
{
    mkdir($outDir) or die "error: couldn't create $outDir directory, $!"; 
}

# Load config files
my @cfg = &load_config_files($inputFile); 

# Generate DOX file
&generate_dox($outDir, \@cfg);

# Generate MB configs
&generate_mb($outDir, \@cfg);

# Generate SMT config
&generate_xport($outDir, \@cfg);

# Generate SCMI config
&generate_scmi($outDir, \@cfg);

# Generate LMM config
&generate_lmm($outDir, \@cfg);

# Generate TRDC config
&generate_trdc($outDir, \@cfg);

# Generate DEV config
&generate_dev($outDir, \@cfg);

# Generate BCTRL config
&generate_bctrl($outDir, \@cfg);

# Generate BOARD config
&generate_board($outDir, \@cfg);

# Generate test config
&generate_test($outDir, \@cfg);

# Generate config makefile
&generate_make($outDir, \@cfg);

if (defined $logFile)
{
    # Close file
    close($log);
}

###############################################################################

sub log_array
{
    my ($banner, $ref) = @_;

    if (defined $logFile)
    {
        print $log &banner($banner);

        # Loop over the array
        foreach (@$ref)
        {
            print $log $_ . "\n";
        }

        print $log "\n\n";
    }
}

###############################################################################

sub load_config_files
{
    my ($cfgFile) = @_;

    # Load input file
    my @cfg = &load_file($cfgFile);

    # Output status
    printf("Parsing ...\n");

    # Log original input files
    &log_array('Input file(s)', \@cfg);

    # Do substitutions
    my $maxLoop = 10;
    while (&do_substitutions(\@cfg) != 0)
    {
        $maxLoop--;
        if ($maxLoop == 0)
        {
            print "error: max recursive substitution reached\n";
            exit;
        }
    }

    # Remove dictionary lines
    @cfg = grep(!/^\w+:/, @cfg);

    # Expand API perms to all protocols
    foreach (@permTypes)
    {
		my $perm = $_;
		my $replace = '';

	    foreach (@protocols)
	    {
	    	$replace .= $_ . "=$perm ";
	    }
		chomp $replace;

	    s/api=$perm\b/$replace/g for @cfg;
	}	    

    # Replace standard perms
    s/perm=none\b/perm=0x0000/g for @cfg;
    s/perm=sec_r\b/perm=0x4400/g for @cfg;
    s/perm=secpriv_rx\b/perm=0x5000/g for @cfg;
    s/perm=secpriv_rw\b/perm=0x6000/g for @cfg;
    s/perm=secpriv_rwx\b/perm=0x7000/g for @cfg;
    s/perm=sec_rw\b/perm=0x6600/g for @cfg;
    s/perm=rw\b/perm=0x6666/g for @cfg;
    s/perm=sec_rwx\b/perm=0x7700/g for @cfg;
    s/perm=ro\b/perm=0x4444/g for @cfg;
    s/perm=nspriv_r\b/perm=0x7740/g for @cfg;
    s/perm=ns_r\b/perm=0x7744/g for @cfg;
    s/perm=nspriv_rw\b/perm=0x6660/g for @cfg;
    s/perm=nspriv_rwx\b/perm=0x7770/g for @cfg;
    s/perm=full\b/perm=0x7777/g for @cfg;

    # Expand SYS/FUSA
    s/^SYS\b/SYS_0/g for @cfg;
    s/^FUSA\b/FUSA_0/g for @cfg;

    # Remove duplicate words
    foreach (@cfg)
    {
        my (%before, @words, @new);

        @words = split(/ /, $_);
        @new = grep { ! $before{$_}++ } @words;
        $_ = join ' ', @new;
    }

    # Default resources to DEV_SM
    foreach my $line (@cfg)
    {
        foreach my $proto (@protocols)
        {
            my $search = uc $proto . '_';

            $line =~ s/\b($search\w+)\b/DEV_SM_$1/g;
        }
    }

    # Remove unused API permissions
    foreach my $line (@cfg)
    {
        foreach my $proto (@protocols)
        {
            my $search = uc $proto . '_';

            if (!($line =~ /_SM_$search/))
            {
                $line =~ s/\b$proto=\w+ //g;
            }
        }
    }

    # Remove perms if no TRDC
    foreach my $line (@cfg)
    {
        if (!(($line =~ /MBC_\w+=/) || ($line =~ /MRC_\w+=/)
            || ($line =~ /MDAC_\w+=/) || ($line =~ /^DOM\d*\b/)
            || ($line =~ /^LM\d*\b/)|| ($line =~ /^DEBUG\b/)))
        {
            $line =~ s/\bdid=\w+ //g;
        }
        if (!(($line =~ /MBC_\w+=/) || ($line =~ /MRC_\w+=/)))
        {
            $line =~ s/\bperm=\w+ //g;
        }
        if (!($line =~ /MDAC_\w+=/))
        {
            $line =~ s/\bsa=\w+ //g;
            $line =~ s/\bpa=\w+ //g;
        }
    }

    # Remove leading/trailing spaces
    s/^\s+|\s+$//g for @cfg;

    # Remove extra spaces
    s/\s+/ /g for @cfg;

    # Append end marker
    push @cfg, 'EOF';

    # Append space at end of every line
    s/$/ /g for @cfg;

    # Log parsed data
    &log_array('Parsed data', \@cfg);

    return @cfg; 
}

###############################################################################

sub load_file
{
    my ($fileName) = @_;
    my @contents;
    my $line = '';
    my $lineNum = 1;

    # Open file
    open my $in, '<', $fileName
        or die "error: failure to open: $fileName, $!";
    if ($verbose)
    {
        my $fn = fileparse($fileName);
        if ($verbose)
        {
            printf("Loading $fn ...\n");
        }
    }

    # Load into array
    while (<$in>)
    {
        # Remove LF
        chomp $_;

        # Continue line?
        if (/\\$/)
        {
            $_ =~ s/\\$//;
            $line .= $_ . ' ';
        }
        elsif (/^include/)
        {
            # Get fileName
            my($first, $rest) = split(/ /, $_, 2);

            # Load include file
            my @inc = &load_file(dirname($fileName) . '/' . $rest);

            # Append to contents
            push @contents, @inc;
        }
        else
        {
            $line .= $_;

            push @contents, $line . ' filename=' . $fileName
                . ' line=' . $lineNum;
            $line = '';
        }
        $lineNum++;
    }

    # Replace ,
    s/,/ /g for @contents;

    # Remove tabs
    s/\t/ /g for @contents;

    # Remove leading/trailing spaces
    s/^\s+|\s+$//g for @contents;

    # Remove extra spaces
    s/\s+/ /g for @contents;

    # Remove empty lines
    @contents = grep(/\S/, @contents);
    @contents = grep(!/^filename=/, @contents);

    # Remove comment lines
    @contents = grep(!/^#/, @contents);

    # Close file
    close($in);

    return @contents;
}

###############################################################################

sub do_substitutions

{
    my ($cfgRef) = @_;
    my @dict;
    my $sub = 0;

    # Loop over device file and search and replace the config
    for my $i (0 .. @$cfgRef-1)
    {
        my $line = ${$cfgRef}[$i];
        my($first, $rest) = split(/ /, $line, 2);

		if ($line =~ /^MIX\b/)
		{
			next;
		}

        # Save/replace dictionary items
        if ($first =~ /:$/)
        {
            # Strip off filename and line
            $line =~ s/ filename=.+$//g;            

            unshift @dict, $line;
        }
        else
        {
            # Do replacements
            foreach (@dict)
            {
                my($first, $rest) = split(/ /, $_, 2);

                # Strip : off end
                $first =~ s/:$//g;          

                # Going to replace?
                if (${$cfgRef}[$i] =~ /\b$first\b/)
                {
                    $sub++;
                }

                # Empty replace
                if (!(defined $rest && length $rest > 0))
                {
                    $rest = '';
                }

                # Replace
                s/\b$first\b/$rest/g for ${$cfgRef}[$i];    
            }
        }
    }

    return $sub;
}

###############################################################################

sub generate_dox
{
    my ($outDir, $cfgRef) = @_;
    my $fileName = 'config.dox';
    my @dox = grep(/^DOX\b/, @$cfgRef);

    # Open file
    open my $out, '>', $outDir . '/' . $fileName
        or die "error: failure to open: $outDir/$fileName, $!";
    if ($verbose)
    {
        my $fn = fileparse($fileName);
        printf("Generating $fn ...\n");
    }

    # Get copyright
    my $cr = &copyright();

	# Get CONFIG name
    if ((my $parm = &param($dox[0], 'name')) ne '!')
    {
		$config_name = 'CONFIG_' . $parm;
    }

 	# Get desc
 	my $config_desc = 'Configuration Data';
	if ($dox[0] =~ /desc=\"([\w\s\.]+)\"/)
	{
		$config_desc = $1;
	}

   # Output copyright
    print $out $cr;

	# Output config group header

	print $out '/*!' . "\n";
	print $out ' * @addtogroup SM_CONFIG' . "\n";
	print $out ' * @{' . "\n";
	print $out ' */' . "\n\n";

	# Output dox group header
	print $out '/*!' . "\n";
	print $out "\n";
	print $out '@defgroup ' . $config_name . ' ' . $config_name
		. ': ' . $config_desc . "\n";
	print $out '' . "\n";
	print $out '@brief Module for ' . $config_desc . '.' . "\n";
	print $out "\n";
	print $out '*/' . "\n\n";

	print $out '/** @} */' . "\n\n";

    # Close file
    close($out);
}

###############################################################################

sub generate_mb
{
    my ($outDir, $cfgRef) = @_;
    my @list = grep(/^MAILBOX\b/ || /^LM\d*\b/ || /^CHANNEL\b/,
    	@$cfgRef);

    # Log MB info
    &log_array('Mailbox info', \@list);

    # Loop over mailbox types
    foreach my $mbt (@mbTypes)
    {
		my $lcMbt = lc $mbt;
        my @mbList = grep(/^MAILBOX\b/ && /type=$lcMbt\b/, @list);
        my $num = @mbList;

        # MU of this type found?
        if ($num > 0)
        {
            my $fileName = 'config_mb_' . lc $mbt . '.h';
            my $i;
            my $x;
            my $xportType = '<invalid>';
            my %xportChannel;
            
            # Open file
            open my $out, '>', $outDir . '/' . $fileName
                or die "error: failure to open: $outDir/$fileName, $!";
            if ($verbose)
            {
                my $fn = fileparse($fileName);
                printf("Generating $fn ...\n");
            }

            # Output header
            print $out &header('MB_' . $mbt, 'MB_' . $mbt);

            print $out '/* Includes */' . "\n\n";
            print $out '#include "mb_' . lc $mbt . '_config.h"' . "\n\n";
            print $out '/* Defines */' . "\n\n";

            # Loop over the LM+MB+CHANNEL list
            $i = -1;
            $x = 0;
            my @defLst;
            foreach my $mb (@list)
            {
                # Handle LM
                if ($mb =~ /^(LM\d*)\b/)
                {
                    my $line = $1 . ' MB_' . $mbt . ' Config';
                    if ((my $parm = &param($mb, 'name')) ne '!')
                    {
                        $parm =~ s/\"//g;
                        $line .= ' (' . $parm . ')';
                    }

	                if ($x != 0)
	                {
	                	print $out '    }' . "\n\n";
		                $x = 0;
	                }
                    print $out &banner($line);
                    next;
                }

                # Handle channel
                if ($mb =~ /^CHANNEL\b/)
                {
	                if ((my $parm = &param($mb, 'xport')) ne '!')
	                {
	                    $xportType = 'XPORT_' . uc $parm;
	                    $xportChannel{$xportType}++;
					}					
	                if ((my $parm = &param($mb, 'db')) ne '!')
	                {
		                print $out '        .xportType[' . $parm
		                	. '] = SM_' . $xportType
		                    . ', \\' . "\n";
		                print $out '        .xportChannel[' . $parm
		                	. '] = ' . ($xportChannel{$xportType}
		                    - 1) . 'U, \\' . "\n";
		                $x++;
		            }
		            else
		            {
                    	error_line('no doorbell', $mb);
		            }
                    next;
                }

                # Handle MB
                if ($mb =~ /^MAILBOX\b/)
                {
	                if ($x != 0)
	                {
	                	print $out '    }' . "\n\n";
		                $x = 0;
	                }
	                $i++;

					my $mu = $i;
	                if ((my $parm = &param($mb, 'mu')) ne '!')
	                {
	                    $mu = $parm;
	                }
					print $out '/*! Config for ' . $mbt . $mu . ' MB */' . "\n";
	                print $out '#define SM_MB_' . $mbt . $mu . '_CONFIG \\' . "\n";
	                print $out '    { \\' . "\n";
	                if ((my $parm = &param($mb, 'mu')) ne '!')
	                {
	                    print $out '        .mu = ' . $parm . 'U, \\' . "\n";
	                }
	                if ((my $parm = &param($mb, 'sma')) ne '!')
	                {
	                    print $out '        .sma = ' . $parm . 'U, \\' . "\n";
	                }
	                if ((my $parm = &param($mb, 'priority')) ne '!')
	                {
	                    print $out '        .priority = IRQ_PRIO_NOPREEMPT_'
	                        . uc $parm . ', \\' . "\n";
	                }
	                $defLst[$i] = $mu;
	            }
            }
            if ($x != -1)
            {
            	print $out '    }' . "\n\n";
                $x = 0;
            }

            # Output collected define
            print $out &banner('MB ' . $mbt . ' Config');
			print $out '/*! Config for number of ' . $mbt . ' MB */' . "\n";
            print $out '#define SM_NUM_MB_' . $mbt . '  '
                . $num . 'U' . "\n\n";

            # Loop over the MB list
            $i = 0;
			print $out '/*! Config data array for ' . $mbt . ' MB */' . "\n";
            print $out '#define SM_MB_' . $mbt . '_CONFIG_DATA';
            foreach my $mb (@mbList)
            {
                if ($i != 0)
                {
                    print $out ',';
                }
                print $out ' \\' . "\n" . '    SM_MB_' . $mbt
                	. $defLst[$i] . '_CONFIG';
                $i++;
            }
            print $out "\n";

            # Output footer
            print $out &footer('MB_' . $mbt);

            # Close file
            close($out);

            # Include in make
            $makeInclude{$mbt} = 'rpc/mb_' . lc $mbt;
        }
    }
}

###############################################################################

sub generate_xport
{
    my ($outDir, $cfgRef) = @_;

    # Loop over xport types
    foreach my $xpt (@xportTypes)
    {
        my $lcXpt = lc $xpt;
        my @list = grep((/^CHANNEL\b/ && /\bxport=$lcXpt\b/)
            || /^MAILBOX\b/ || /^LM\d*\b/, @$cfgRef);
        my @chnList = grep(/^CHANNEL\b/, @list);
        my $num = @chnList;

        # Log xport info
        &log_array('Transort info (' . $xpt . ')', \@list);

        # Channels found?
        if ($num > 0)
        {
            my $fileName = 'config_' . $lcXpt . '.h';
            my $i;
            my $rpcType = '<invalid>';
            my %rpcChannel;
            my $mbType = '<invalid>';
            my %mbInst;
            my %crc;
            
            # Open file
            open my $out, '>', $outDir . '/' . $fileName
                or die "error: failure to open: $outDir/$fileName, $!";
            if ($verbose)
            {
                my $fn = fileparse($fileName);
                printf("Generating $fn ...\n");
            }

            # Output header
            print $out &header($xpt, $xpt);

            print $out '/* Includes */' . "\n\n";
            print $out '#include "rpc_' . $lcXpt . '_config.h"' . "\n\n";
            print $out '/* Defines */' . "\n\n";

            # Loop over the LM+MU+CHN list
            $i = 0;
            foreach my $mb (@list)
            {
                # Handle LM
                if ($mb =~ /^(LM\d*)\b/)
                {
                    my $line = $1 . ' ' . $xpt . ' Config';
                    if ((my $parm = &param($mb, 'name')) ne '!')
                    {
                        $parm =~ s/\"//g;
                        $line .= ' (' . $parm . ')';
                    }

                    print $out &banner($line);
                    next;
                }

                # Handle MB
                if ($mb =~ /^MAILBOX\b/)
                {
	                if ((my $parm = &param($mb, 'type')) ne '!')
	                {
	                    $mbType = 'MB_' . uc $parm;
	                    $mbInst{$mbType}++;
	                }
                    next;
                }

                # Handle channel
                if ($mb =~ /^CHANNEL\b/)
                {
	                if ((my $parm = &param($mb, 'rpc')) ne '!')
	                {
	                    $rpcType = 'RPC_' . uc $parm;
	                    $rpcChannel{$rpcType}++;
	                }

	                # Check for default channel
	                if ($mbType eq '<invalid>')
	                {
	                    error_line('no mailbox', $mb);
	                }

	                # Output channel define
					print $out '/*! Config for ' . $xpt . ' channel ' . $i
						. ' */' . "\n";
	                print $out '#define SM_' . $xpt . '_CHN'
	                    . $i . '_CONFIG \\' . "\n";
	                print $out '    { \\' . "\n";
	                print $out '        .rpcType = SM_' . $rpcType
	                    . ', \\' . "\n";
	                print $out '        .rpcChannel = ' . ($rpcChannel{$rpcType}
	                    - 1) . 'U, \\' . "\n";
	                print $out '        .mbType = SM_' . $mbType
	                    . ', \\' . "\n";
	                print $out '        .mbInst = ' . ($mbInst{$mbType}
	                    - 1) . 'U, \\' . "\n";
	                if ((my $parm = &param($mb, 'db')) ne '!')
	                {
	                    print $out '        .mbDoorbell = ' . $parm
	                        . 'U, \\' . "\n";
	                }
	                if ((my $parm = &param($mb, 'check')) ne '!')
	                {
	                    $crc{$parm}++;
	                    print $out '        .crc = SM_SMT_CRC_'
	                        . uc $parm . ', \\' . "\n";
	                }
	                print $out '    }' . "\n\n";

	                $i++;
	            }
            }

            # Output collected define
            print $out &banner($xpt . ' Config');
			print $out '/*! Config for number of ' . $xpt . ' channels'
						. ' */' . "\n";
            print $out '#define SM_NUM_' . $xpt . '_CHN  '
                . $num . 'U' . "\n\n";

            # Loop over the channel list
            $i = 0;
			print $out '/*! Config data array for ' . $xpt . ' channels */' . "\n";
            print $out '#define SM_' . $xpt . '_CHN_CONFIG_DATA';
            foreach my $chn (@chnList)
            {
                if ($i != 0)
                {
                    print $out ',';
                }
                print $out ' \\' . "\n" . '    SM_' . $xpt . '_CHN'
                    . $i . '_CONFIG';
                $i++;
            }
            print $out "\n\n";

            # Output defines for MU type support
            print $out '/* Mailbox and CRC types to support */'
                . "\n";
            foreach my $key (keys %mbInst)
            {
                my $value = $mbInst{$key};

                if ($value != 0)
                {
					print $out '/*! Config for ' . uc $key . ' use */' . "\n";
                    print $out '#define USES_' . uc $key . "\n";
                }
            }

            # Output defines for CRC support
            foreach my $key (sort keys %crc)
            {
                my $value = $crc{$key};

                if ($value != 0)
                {
					print $out '/*! Config for ' . uc $key . ' CRC use */' . "\n";
                    print $out '#define USES_CRC_' . uc $key . "\n";
                }
            }

            # Output footer
            print $out &footer($xpt);

            # Close file
            close($out);

            # Include in make
            $makeInclude{$xpt} = 'rpc/' . $lcXpt;
        }
    }
}

###############################################################################

sub generate_scmi
{
    my ($outDir, $cfgRef) = @_;
    my $fileName = 'config_scmi.h';
    my @list = @$cfgRef;
    my @chnList = grep(/^CHANNEL\b/ && /\brpc=scmi\b/, @list);
    my $numChn = @chnList;
    my @agntList = grep(/^SCMI_AGENT\d*\b/, @list);
    my $numAgnt = @agntList;
    my $i;
    my %xportInst;

    # Open file
    open my $out, '>', $outDir . '/' . $fileName
        or die "error: failure to open: $outDir/$fileName, $!";
    if ($verbose)
    {
        my $fn = fileparse($fileName);
        printf("Generating $fn ...\n");
    }

    # Log channel info
    &log_array('SCMI channel info', \@chnList);

    # Log agent info
    &log_array('SCMI agent info', \@agntList);

    # Output header
    print $out &header('SCMI', 'SCMI RPC');

    print $out '/* Defines */' . "\n\n";

    # Loop over the list
    my $scmiInst = -1;
    my $lmName = '<invalid>';
    my $did = '<invalid>';
    my $lmId = -1;
    my $agnt = -1;
    my $numAgents = 0;
    my $firstAgent;
    my $chn = 0;
    my $notify = 20;
    my $safe = 0;
    foreach my $dat (@list)
    {
        # Handle LM and EOF
        if (($dat =~ /^(LM\d*)\b/) || ($dat =~ /^EOF\b/)) 
        {
            # Non-first LM
            if ($scmiInst != -1)
            {
                if ($lmName eq '<invalid>')
                {
                    error_line('missing LM, invalid SCMI instance', $dat);
                }

                my $line = 'SCMI Instance ' . $scmiInst
                    . ' Config (' . $lmName . ')';
                print $out &banner($line);

				print $out '/*! Config for SCMI instance ' . $scmiInst
					. ' */' . "\n";
                print $out '#define SM_SCMI' . $scmiInst
                    . '_CONFIG \\' . "\n";
                print $out '    { \\' . "\n";
                print $out '        .lmId = ' . $lmId
                    . 'U, \\' . "\n";
                print $out '        .numAgents = ' . $numAgents
                    . 'U, \\' . "\n";
                print $out '        .firstAgent = ' . $firstAgent
                    . 'U, \\' . "\n";

                print $out '    }' . "\n\n";

                $numAgents = 0;
            }

            # Handle LM
            if ($dat =~ /^(LM\d*)\b/)
            {
                # SCMI LM?
                if ($dat =~ /\brpc=scmi\b/)
                {
                    if ((my $parm = &param($dat, 'name')) ne '!')
                    {
                        $parm =~ s/\"//g;
                        $lmName = $parm;
                    }
                    if ((my $parm = &param($dat, 'did')) ne '!')
                    {
                        $did = $parm;
                    }
                    $scmiInst++;
                }
                else
                {
                    $lmName = '<invalid>';
                    $did = '<invalid>';
                }
                $firstAgent = $agnt + 1;
                $lmId++;

                # Check safety type
                $safe = 0;
       	        if ((my $parm = &param($dat, 'safe')) ne '!')
    	        {
                    if ($parm eq 'seenv')
                    {
                        $safe = 1;
                    }
    	        }
            }

            next;
        }

        # Handle agent
        if ($dat =~ /^(SCMI_AGENT\d*)\b/)
        {
            my $agentToken = $1;
            $agentToken =~ s/_/ /g; 
            my $line = $agentToken . ' Config';
    		my $secure = 0;
            my $dup;
            if ((my $parm = &param($dat, 'name')) ne '!')
            {
                $parm =~ s/\"//g;
                $line .= ' (' . $parm . ')';
            }
            if ((my $parm = &param($dat, 'did')) ne '!')
            {
                $did = $parm;
            }
            if ($dat =~ /secure /)
            {
                $secure = 1;
            }
            else
            {
                $secure = 0;
            }
            $agnt++;
            $numAgents++;
            if ((my $parm = &param($dat, 'dup')) ne '!')
            {
                $dup = $parm;
            }
            else
            {
                $dup = $agnt;
            }

            if ($safe == 1)
            {
                $seenvid++;
            }

            # Output banner
            print $out &banner($line);

            # Check SCMI instance
            if ($scmiInst < 0)
            {
                error_line('missing LM, invalid SCMI instance', $dat);
            }

            # Get perms
            my @perms = &get_perms($cfgRef, $dup);

            # Output agent info
			print $out '/*! Config for SCMI agent ' . $agnt
				. ' */' . "\n";
            print $out '#define SM_SCMI_AGNT' . $agnt . '_CONFIG \\'
                . "\n";
            print $out '    { \\' . "\n";
            if ((my $parm = &param($dat, 'name')) ne '!')
            {
                $parm =~ s/\"//g;
                print $out '        .name = "' . $parm . '", \\' . "\n";
            }
            print $out '        .scmiInst = ' . $scmiInst . 'U, \\' . "\n";
            print $out '        .domId = ' . $did . 'U, \\' . "\n";
            print $out '        .secure = ' . $secure . 'U, \\' . "\n";
            if ($safe == 1)
            {
                print $out '        .seenvId = ' . $seenvid . 'U, \\' . "\n";
            }

            # Loop over perms
            $i = 0;
            foreach my $perm (@perms)
            {
                print $out '        ' . $perm . ', \\' . "\n";
                $i++;
            }
            print $out '    }' . "\n\n";

            next;
        }

        # Handle channel
        if ($dat =~ /^CHANNEL\b/)
        {
            if ((my $parm = &param($dat, 'xport')) ne '!')
            {
                $xportInst{$parm}++;
            }
            if ((my $parm = &param($dat, 'rpc')) eq 'scmi')
            {
				print $out '/*! Config for SCMI channel ' . $chn
					. ' */' . "\n";
	            print $out '#define SM_SCMI_CHN' . $chn
	                . '_CONFIG \\' . "\n";
	            print $out '    { \\' . "\n";
	            print $out '        .agentId = ' . $agnt . 'U, \\' . "\n";
	            if ((my $parm = &param($dat, 'type')) ne '!')
	            {
	                print $out '        .type = SM_SCMI_CHN_'
	                    . uc $parm . ', \\' . "\n";
	            }
	            if ((my $parm = &param($dat, 'sequence')) ne '!')
	            {
	                print $out '        .sequence = SM_SCMI_SEQ_'
	                    . uc $parm . ', \\' . "\n";
	            }
	            if ((my $parm = &param($dat, 'xport')) ne '!')
	            {
	                print $out '        .xportType = SM_XPORT_'
	                    . uc $parm . ', \\' . "\n";
	                print $out '        .xportChannel = '
	                    . ($xportInst{$parm} - 1) . 'U, \\' . "\n";
	            }
	            if ((my $parm = &param($dat, 'notify')) ne '!')
	            {
	                $notify = $parm;
	            }
	            print $out '    }' . "\n\n";
	            $chn++;

	            # Include in make
	            $makeInclude{SCMI} = 'rpc/scmi';
	        }

            next;
        }
   }

    # Output collected agent define
    print $out &banner('SCMI Agent Config');
	print $out '/*! Config for number of SCMI agents */' . "\n";
    print $out '#define SM_SCMI_NUM_AGNT  ' . $numAgnt . 'U' . "\n\n";

    # Loop over the agent list
	print $out '/*! Config data array for SCMI agents */' . "\n";
    print $out '#define SM_SCMI_AGNT_CONFIG_DATA';
    foreach my $i (0..($numAgnt - 1))
    {
        if ($i != 0)
        {
            print $out ',';
        }
        print $out ' \\' . "\n" . '    SM_SCMI_AGNT' . $i . '_CONFIG';
    }
    print $out "\n\n";

    # Output collected channel define
    print $out &banner('SCMI Channel Config');
	print $out '/*! Config for number of SCMI channels */' . "\n";
    print $out '#define SM_SCMI_NUM_CHN  ' . $numChn . 'U' . "\n\n";

    # Loop over the channel list
	print $out '/*! Config data array for SCMI channels */' . "\n";
    print $out '#define SM_SCMI_CHN_CONFIG_DATA';
    foreach my $i (0..($numChn - 1))
    {
        if ($i != 0)
        {
            print $out ',';
        }
        print $out ' \\' . "\n" . '    SM_SCMI_CHN' . $i . '_CONFIG';
    }
    print $out "\n\n";

    # Output collected SCMI define
    print $out &banner('SCMI Config');
	print $out '/*! Config for number of SCMI instances */' . "\n";
    print $out '#define SM_NUM_SCMI  ' . ($scmiInst + 1) . 'U' . "\n\n";

    # Loop over the SCMI list
	print $out '/*! Config data array for SCMI instances */' . "\n";
    print $out '#define SM_SCMI_CONFIG_DATA';
    foreach my $i (0..$scmiInst)
    {
        if ($i != 0)
        {
            print $out ',';
        }
        print $out ' \\' . "\n" . '    SM_SCMI' . $i . '_CONFIG';
    }
    print $out "\n\n";

    print $out '/*! Max words to buffer for notification messages */'
        . "\n";
    print $out '#define SM_SCMI_MAX_NOTIFY  ' . $notify . 'U' . "\n";

    # Output footer
    print $out &footer('SCMI');

    # Close file
    close($out);
}

###############################################################################

sub generate_lmm
{
    my ($outDir, $cfgRef) = @_;
    my $fileName = 'config_lmm.h';
    my %rpcInst;
    my $default = 0;

    # Open file
    open my $out, '>', $outDir . '/' . $fileName
        or die "error: failure to open: $outDir/$fileName, $!";
    if ($verbose)
    {
        my $fn = fileparse($fileName);
        printf("Generating $fn ...\n");
    }

    # Output header
    print $out &header('LMM', 'logical machine manager');

    print $out '/* Defines */' . "\n\n";

	# Get list of start/stop */
    my @ss = grep(/^LM\d*\b/ || /\bstart=/ || /\bstop=/, @$cfgRef);

    # Log ss info
    &log_array('LMM start/stop info', \@ss);

    # Loop over the start/stop list
    my $i = 0;
    my $lm_handle = 0;
    my @start;
    my @stop;
    foreach my $s (@ss)
    {
		# Handle LM
		if ($s =~ /^LM(\d*)\b/)
		{
	        $lm_handle = $1;
		}

		# Handle start
		if ($s =~ /\bstart=/)
		{
	        # Loop over protocols
	        foreach my $proto (@protocols)
	        {
	            # Get resources
	            my $ucProto = uc $proto . '_';
	            my @words = split(/ /, $s);
	            my @resources = grep(/^[A-Z]+_SM_$ucProto/, @words);

	            # Loop over resources
	            foreach my $rsrc (@resources)
	            {
					# Begin with lm
					my $srt = sprintf("%03d", $lm_handle);
					my $slist = 'lm=' . $lm_handle;

					# Append msel
			        if ((my $parm = &param($s, 'msel')) ne '!')
			        {
					    $slist .= ' msel=' . $parm;
                    }
                    else
                    {
					    $slist .= ' msel=0';
                    }

					# Append start
			        if ((my $parm = &param($s, 'start')) ne '!')
			        {
	           			my @arg = split(/\|/, $parm);

	           			$srt .= sprintf("%04d", $arg[0]);
						$slist .= ' arg=' . $parm;
			        }

					# Append protocol
					$slist .= ' ss=LMM_SS_' . uc $proto;

					# Append resource
					$slist .= ' rsrc=' . $rsrc;
					
			        push @start, $srt . ': ' . $slist . ' ';
		        }
		    }
		}

		# Handle stop
		if ($s =~ /\bstop=/)
		{
	        # Loop over protocols
	        foreach my $proto (@protocols)
	        {
	            # Get resources
	            my $ucProto = uc $proto . '_';
	            my @words = split(/ /, $s);
	            my @resources = grep(/^[A-Z]+_SM_$ucProto/, @words);

	            # Loop over resources
	            foreach my $rsrc (@resources)
	            {
					# Begin with lm
					my $srt = sprintf("%03d", $lm_handle);
					my $slist = 'lm=' . $lm_handle;

					# Append msel
			        if ((my $parm = &param($s, 'msel')) ne '!')
			        {
					    $slist .= ' msel=' . $parm;
                    }
                    else
                    {
					    $slist .= ' msel=0';
                    }

					# Append start
			        if ((my $parm = &param($s, 'stop')) ne '!')
			        {
	           			my @arg = split(/\|/, $parm);

	           			$arg[0] = sprintf("%04d", $arg[0]);

	           			$srt .= sprintf("%04d", $arg[0]);
						$slist .= ' arg=' . $parm;
			        }

					# Append protocol
					$slist .= ' ss=LMM_SS_' . uc $proto;

					# Append resource
					$slist .= ' rsrc=' . $rsrc;
					
			        push @stop, $srt . ': ' . $slist . ' ';
		        }
		    }
		}
	}

	# Sort results
	my @tmp = sort @start;
	@start = @tmp;
	@tmp = sort @stop;
	@stop = @tmp;

	# Get list of LM
    my @list = grep(/^LM\d*\b/ || /^MODE\b/, @$cfgRef);

    # Log LM info
    &log_array('LMM info', \@list);

    # Loop over the LM list
    $i = 0;
    my $msel = 0;
    my $maxMsel = 0;
    foreach my $lm (@list)
    {
        my $rpcType;

		# Handle LM
		if ($lm =~ /^(LM\d*)\b/)
		{
            $msel = 0;

            # Close previous LM
			if ($i != 0)
			{
				print $out '    }' . "\n\n";
			}

	        # Output banner
			$lm =~ /^LM(\d*)\b/;
	        my $lm_val = $1;
	        $lm =~ /^(LM\d*)\b/;
	        my $lm_handle = $1;
	        my $line = $1 . ' Config';
	        if ((my $parm = &param($lm, 'name')) ne '!')
	        {
	            $parm =~ s/\"//g;
	            $line .= ' (' . $parm . ')';
	        }
	        print $out &banner($line);

	        # Output LM define
			print $out '/*! Config for ' . $lm_handle . ' */' . "\n";
	        print $out '#define SM_' . $lm_handle . '_CONFIG \\' . "\n";
	        print $out '    { \\' . "\n";
	        if ((my $parm = &param($lm, 'name')) ne '!')
	        {
	            $parm =~ s/\"//g;
	            print $out '        .name = "' . $parm . '", \\' . "\n";
	        }
	        if ((my $parm = &param($lm, 'rpc')) ne '!')
	        {
	            $rpcType = $parm;
	            print $out '        .rpcType = SM_RPC_'
	                . uc $parm . ', \\' . "\n";
	            $rpcInst{$parm}++;
	        }
			if ($rpcType ne 'none')
			{
	        	print $out '        .rpcInst = '
	        		. ($rpcInst{$rpcType} - 1)
	            	. 'U, \\' . "\n";
	        }
	        if ((my $parm = &param($lm, 'boot')) ne '!')
	        {
	            print $out '        .boot[0] = ' . $parm . 'U, \\' . "\n";
	            $rpcInst{$parm}++;
	        }
	        if ((my $parm = &param($lm, 'skip')) ne '!')
	        {
	            print $out '        .bootSkip[0] = ' . $parm . 'U, \\' . "\n";
	            $rpcInst{$parm}++;
	        }
	        if ((my $parm = &param($lm, 'rtime')) ne '!')
	        {
	            print $out '        .rtime = ' . $parm . 'U, \\' . "\n";
	        }

            # Output safety type
   	        if ((my $parm = &param($lm, 'safe')) ne '!')
	        {
	            print $out '        .safeType = LMM_SAFE_TYPE_' . uc $parm
	                . ', \\' . "\n";
	        }

            # Output group
   	        if ((my $parm = &param($lm, 'group')) ne '!')
	        {
	            print $out '        .group = ' . $parm . 'U, \\' . "\n";
	        }

            # Output auto boot
   	        if ((my $parm = &param($lm, 'auto')) ne '!')
	        {
	            print $out '        .autoBoot = LMM_AUTO_' . uc $parm
	                . ', \\' . "\n";
	        }

			# Output start/stop
			my $sidx = first { $start[$_] =~ /lm=$lm_val/ } 0..$#start;
			if (defined $sidx)
			{
				my $n = $sidx + 1;
	            print $out '        .start = ' . $n . 'U, \\' . "\n";		
			}
			$sidx = first { $stop[$_] =~ /lm=$lm_val/ } 0..$#stop;
			if (defined $sidx)
			{
				my $n = $sidx + 1;
	            print $out '        .stop = ' . $n . 'U, \\' . "\n";		
			}

			# Save default
	        if ($lm =~ /default /)
	        {
	            $default = $i;
	        }

	        # Include in make
	        $makeInclude{LMM} = 'lmm';

	        $i++;
	    }

    	# Handle MODE
    	if ($lm =~ /^MODE\b/)
    	{
	        if ((my $parm = &param($lm, 'msel')) ne '!')
	        {
	            $msel = $parm;
	            if ($msel > $maxMsel)
	            {
	                $maxMsel = $msel;
	            }
	        }
	        if ((my $parm = &param($lm, 'boot')) ne '!')
	        {
	            print $out '        .boot[' . $msel . '] = ' . $parm . 'U, \\' . "\n";
	            $rpcInst{$parm}++;
	        }
	        if ((my $parm = &param($lm, 'skip')) ne '!')
	        {
	            print $out '        .bootSkip[' . $msel . '] = ' . $parm . 'U, \\' . "\n";
	            $rpcInst{$parm}++;
	        }
        }
    }

	# Close previous LM
	if ($i != 0)
	{
		print $out '    }' . "\n\n";
	}

    # Output collected define
    my @lm_list = grep(/^LM\d*\b/, @list);
    my $num = @lm_list;
    print $out &banner('LM Config');
	print $out '/*! Config for number of LM */' . "\n";
    print $out '#define SM_NUM_LM  ' . $num . 'U' . "\n\n";

    # Loop over the LM list
    $i = 0;
	print $out '/*! Config data array for LM */' . "\n";
    print $out '#define SM_LM_CONFIG_DATA';
    foreach my $lm (@lm_list)
    {
        $lm =~ /^(LM\d*)\b/;
        my $lm_handle = $1;
        if ($i != 0)
        {
            print $out ',';
        }
        print $out ' \\' . "\n" . '    SM_' . $lm_handle . '_CONFIG';
        $i++;
    }
    print $out "\n\n";

	# Output max msel
    print $out '/*! Number of  mSel */' . "\n";
    print $out '#define SM_LM_NUM_MSEL  ' . ($maxMsel + 1) . 'U' . "\n\n";

	# Output max num seenv
    print $out '/*! Number of  S-EENV */' . "\n";
    print $out '#define SM_LM_NUM_SEENV  ' . ($seenvid) . 'U' . "\n\n";

	# Output config name
    my ($inName, $inPath, $inSuffix) = fileparse($inputFile, '\.[^\.]*');
    print $out '/*! Config name */' . "\n";
    print $out '#define SM_LM_CFG_NAME  "' . substr($inName, 0, 15)
        . '"' . "\n\n";

	# Output default monitor LM
    print $out '/*! Default LM for monitor */' . "\n";
    print $out '#define SM_LM_DEFAULT  ' . $default . 'U' . "\n\n";

    # Output start
    print $out &banner('LM Start/Stop Lists');
    my $numStart = @start;
    print $out '/*! Config for number of start */' . "\n";
    print $out '#define SM_LM_NUM_START  ' . $numStart . 'U' . "\n\n";
    print $out '/*! LM start list */' . "\n";
    print $out '#define SM_LM_START_DATA';
	print $out &startstop($numStart, \@start);
    print $out "\n";

    # Output stop
    my $numStop = @stop;
    print $out '/*! Config for number of stop */' . "\n";
    print $out '#define SM_LM_NUM_STOP  ' . $numStop . 'U' . "\n\n";
    print $out '/*! LM stop list */' . "\n";
    print $out '#define SM_LM_STOP_DATA';
	print $out &startstop($numStop, \@stop);
    print $out "\n";

    # Output fault
    print $out &banner('LM Fault Lists');
    print $out '/*! LM fault reactions */' . "\n";
    print $out '#define SM_LM_FAULT_DATA';

	# Get list of faults */
    my @fault = grep(/^LM\d*\b/ || /\bDEV_SM_FAULT_/, @$cfgRef);
    foreach my $f (@fault)
    {
		# Handle LM
		if ($f =~ /^LM(\d*)\b/)
		{
	        $lm_handle = $1;
		}

		# Handle fault
		if ($f =~ /\bDEV_SM_FAULT_(\w*)\b/)
		{
            my $faultParm = $lm_handle;
            my $fault = 'DEV_SM_FAULT_' . $1;

	        if ((my $parm = &param($f, 'reaction')) ne '!')
	        {
                # Get optional parm
    	        if ((my $arg = &param($f, 'lm')) ne '!')
    	        {
    	            $faultParm = $arg;
    	        }

                print $out ' \\' ."\n" . '    [' . $fault . '] = {';
                print $out '.reaction = LMM_REACT_' . uc $parm . ', ';
                print $out '.lm = ' . $faultParm . 'U},';
 	        }
	    }
    }
    print $out "\n";

    # Output footer
    print $out &footer('LMM');

    # Close file
    close($out);
}

###############################################################################

sub generate_dev
{
    my ($outDir, $cfgRef) = @_;
    my $fileName = 'config_dev.h';

    my @dat = grep(/^MIX\b/, @$cfgRef);

    # Skip if the file already exists
    if (-e $outDir . '/' . $fileName)
    {
        return;
    }

    # Open file
    open my $out, '>', $outDir . '/' . $fileName
        or die "error: failure to open: $outDir/$fileName, $!";
    if ($verbose)
    {
        my $fn = fileparse($fileName);
        printf("Generating $fn ...\n");
    }

    # Output header
    print $out &header('DEV', 'device abstraction');

    print $out '/* Includes */' . "\n\n";
    print $out '#include "config.h"' . "\n\n";
    print $out '/* Defines */' . "\n";

	# Output mix defines
    foreach my $mix (@dat)
    {
        if ((my $parm = &param($mix, 'name')) ne '!')
        {
			print $out "\n";
			print $out &banner($parm . ' Config');

			print $out '/*! Data load config for the ' . (uc $parm) . ' mix */' . "\n";
			print $out '#define SM_' . uc $parm . '_CONFIG \\' . "\n";
			print $out '    { \\' . "\n";
			print $out '        SM_CFG_END \\' . "\n";
			print $out '    }' . "\n";
        }
	}

    # Output footer
    print $out &footer('DEV');

    # Close file
    close($out);
}

###############################################################################

sub generate_bctrl
{
    my ($outDir, $cfgRef) = @_;
    my $fileName = 'config_bctrl.h';

    my @dat = grep(/^MIX\b/, @$cfgRef);

    # Open file
    open my $out, '>', $outDir . '/' . $fileName
        or die "error: failure to open: $outDir/$fileName, $!";
    if ($verbose)
    {
        my $fn = fileparse($fileName);
        printf("Generating $fn ...\n");
    }

    # Get block control list
    my @list = grep(/^BCTRL_CONFIG_/, @$cfgRef);

    # Get block control data
    my @bdata = &get_bctrl($cfgRef);

    # Output header
    print $out &header('BCTRL', 'device block controls');

    print $out '/* Includes */' . "\n\n";
    print $out '#include "config.h"' . "\n\n";
    print $out '/* Defines */' . "\n";

    # Loop over the block control list
    foreach my $b (@list)
    {
        if ($b =~ /BCTRL_CONFIG_(\w+) /)
        {
            my $bctrl = $1;    
    		my @avpBctrl = grep(/^$bctrl: /i, @bdata);
    		my $line = 'BCTRL ' . $bctrl . ' Config';
    	    print $out "\n" . &banner($line);

    		print $out '/*! Config for BCTRL ' . $bctrl
    			. ' */' . "\n";
    		print $out '#define SM_BCTRL_' . $bctrl . '_CONFIG \\' . "\n";
        	print $out '    { \\' . "\n";

    		print $out  &compress_data(@avpBctrl);

    		# Mark end
        	print $out '        SM_CFG_END \\' . "\n";
        	print $out '    }' . "\n";
        }
    }

    # Output footer
    print $out &footer('BCTRL');

    # Close file
    close($out);
}

###############################################################################

sub generate_board
{
    my ($outDir, $cfgRef) = @_;
    my $fileName = 'config_board.h';
	my $w = 28;
    my @list = grep(/^BOARD\b/, @$cfgRef);
	my $debugUartInstance = '0';
	my $debugUartBaudrate = '115200';
	my $pmicI2cInstance = '0';
	my $boardI2cBaudrate = '100000';

    # Open file
    open my $out, '>', $outDir . '/' . $fileName
        or die "error: failure to open: $outDir/$fileName, $!";
    if ($verbose)
    {
        my $fn = fileparse($fileName);
        printf("Generating $fn ...\n");
    }

    # Output header
    print $out &header('BOARD', 'board abstraction');

    print $out '/* Includes */' . "\n\n";
    print $out '#include "config.h"' . "\n\n";
    print $out '/* Defines */' . "\n\n";

	# Output board defines
    foreach my $line (@list)
    {
		$line =~ /\b([A-Z0-9_]+)=([\w\-\.\/"\|]+)\s/ || next;
		my ($key, $value) = ($1, $2);

		if ($key eq 'DEBUG_UART_INSTANCE')
		{
			$debugUartInstance = $value;
		}
		elsif ($key eq 'DEBUG_UART_BAUDRATE')
		{
			$debugUartBaudrate = $value;
		}
		elsif ($key eq 'I2C_INSTANCE')
		{
			$pmicI2cInstance = $value;
		}
		elsif ($key eq 'I2C_BAUDRATE')
		{
			$boardI2cBaudrate = $value;
		}
		else
		{
			print $out '/*! ' . $key . ' from cfg file */' . "\n";
			print $out sprintf("#define %*s %s\n\n", -$w,
				'BOARD_' . $key, $value);
		}
	}	

    # UART instance
	print $out '/*! Config for UART instance */' . "\n";
	print $out sprintf("#define %*s %sU\n", -$w,
		'BOARD_DEBUG_UART_INSTANCE', $debugUartInstance);

    # UART baudrate
	print $out '/*! Config for UART baudrate */' . "\n";
	print $out sprintf("#define %*s %sU\n\n", -$w,
		'BOARD_DEBUG_UART_BAUDRATE', $debugUartBaudrate);

    # I2C instance
	print $out '/*! Config for PMIC I2C instance */' . "\n";
	print $out sprintf("#define %*s %sU\n", -$w,
		'BOARD_I2C_INSTANCE', $pmicI2cInstance);

    # I2C baudrate
	print $out '/*! Config for PMIC I2C baudrate */' . "\n";
	print $out sprintf("#define %*s %sU\n", -$w,
		'BOARD_I2C_BAUDRATE', $boardI2cBaudrate);

    # Output footer
    print $out &footer('BOARD');

    # Close file
    close($out);
}

###############################################################################

sub generate_trdc
{
    my ($outDir, $cfgRef) = @_;
    my $fileName = 'config_trdc.h';

    # Open file
    open my $out, '>', $outDir . '/' . $fileName
        or die "error: failure to open: $outDir/$fileName, $!";
    if ($verbose)
    {
        my $fn = fileparse($fileName);
        printf("Generating $fn ...\n");
    }

	# Get TRDC list
    my $trdcRef = &get_trdc_config($cfgRef);

    # Get TRDC data
    my @rdc = &get_trdc($cfgRef, $trdcRef);

    # Log TRDC data
    &log_array('TRDC processed data', \@rdc);

	# Convert to address value pairs
    my @avp = &convert_trdc(\@rdc, $trdcRef);

    # Output header
    print $out &header('TRDC', 'TRDC SM abstraction');

    print $out '/* Includes */' . "\n\n";
    print $out '#include "config.h"' . "\n\n";
    print $out '/* Defines */' . "\n";

    # Loop over the TRDC list
    foreach my $trdc (sort keys %$trdcRef)
    {
		my @avpTrdc = grep(/^$trdc: /i, @avp);
		my $line = 'TRDC ' . $trdc . ' Config';
	    print $out "\n" . &banner($line);

		print $out '/*! Config for TRDC ' . $trdc
			. ' */' . "\n";
		print $out '#define SM_TRDC_' . $trdc . '_CONFIG \\' . "\n";
    	print $out '    { \\' . "\n";

		print $out  &compress_data(@avpTrdc);

		# Enable TRDC
		print $out '        SM_CFG_C1(0x00000000U), 0x0000C001U, \\'
			. "\n";

		# Mark end
    	print $out '        SM_CFG_END \\' . "\n";
    	print $out '    }' . "\n";
	}

    # Output footer
    print $out &footer('TRDC');

    # Close file
    close($out);
}

###############################################################################

sub generate_test
{
    my ($outDir, $cfgRef) = @_;
    my $fileName = 'config_test.h';

    my @list = grep(/^CHANNEL\b/ || /^MAILBOX\b/ || /^LM\d*\b/
        || /^SCMI_AGENT\d*\b/,
        @$cfgRef);
    my @chnList = grep(/^CHANNEL\b/, @list);
    my $numChn = @chnList;
    my $i;
    
    # Open file
    open my $out, '>', $outDir . '/' . $fileName
        or die "error: failure to open: $outDir/$fileName, $!";
    if ($verbose)
    {
        my $fn = fileparse($fileName);
        printf("Generating $fn ...\n");
    }

    # Output header
    print $out &header('TEST', 'unit tests');

    print $out '/* Defines */' . "\n\n";

    # Loop over the LM+MB list
    $i = 0;
    my $mbInst = -1;
    my $defaultTest = '<invalid>';
    my $mbType = '<invalid>';
    my $mbSma = '<invalid>';
    my $agnt = -1;
    foreach my $dat (@list)
    {
        # Handle LM
        if ($dat =~ /^(LM\d*)\b/)
        {
            my $line = $1 . ' Test Config';
            if ((my $parm = &param($dat, 'name')) ne '!')
            {
                $parm =~ s/\"//g;
                $line .= ' (' . $parm . ')';
            }

            print $out &banner($line);
            next;
        }

        # Handle agent
        if ($dat =~ /^(SCMI_AGENT\d*)\b/)
        {
            $agnt++;
            next;
		}

        # Handle mailbox
        if ($dat =~ /^MAILBOX\b/)
        {
            if ((my $parm = &param($dat, 'type')) ne '!')
            {
                $mbType = 'MB_' . uc $parm;
            }
            if ((my $parm = &param($dat, 'test')) ne '!')
            {
                $mbInst = $parm;
            }
            else
            {
                $mbInst++;
            }
            if ((my $parm = &param($dat, 'sma')) ne '!')
            {
                $mbSma = $parm;
            }
            else
            {
                $mbSma = '<invalid>';
            }
            next;
        }

        # Check mailbox
        if ($mbInst == -1)
        {
            error_line('missing mailbox', $dat);       
        }

        # Output channel define
		print $out '/*! Config for test channel ' . $i
			. ' */' . "\n";
        print $out '#define SM_TEST_CHN'
            . $i . '_CONFIG \\' . "\n";
        print $out '    { \\' . "\n";
        print $out '        .mbInst = ' . $mbInst
            . 'U, \\' . "\n";
        if ((my $parm = &param($dat, 'db')) ne '!')
        {
            print $out '        .mbDoorbell = ' . $parm
                . 'U, \\' . "\n";
        }
        else
        {
            error_line('missing doorbell (db)', $dat);
        }
        if ($mbSma ne '<invalid>')
        {
            print $out '        .sma = ' . $mbSma
                . 'U, \\' . "\n";
        }
        print $out '        .agentId = ' . $agnt
            . 'U, \\' . "\n";
        print $out '    }' . "\n\n";

        # Save default
        if ($dat =~ /\btest=default\b/)
        {
            $defaultTest = $i;
        }

        $i++;
    }

    # Output collected define
    print $out &banner('Test Channel Config');
	print $out '/*! Config for number of test channels */' . "\n";
    print $out '#define SM_NUM_TEST_CHN  '
        . $numChn . 'U' . "\n\n";

    # Loop over the MU list
	print $out '/*! Config data array for test channels */' . "\n";
    print $out '#define SM_TEST_CHN_CONFIG_DATA';
    foreach my $i (0..($numChn - 1))
    {
        if ($i != 0)
        {
            print $out ',';
        }
        print $out ' \\' . "\n" . '    SM_TEST_CHN' . $i . '_CONFIG';
    }
    print $out "\n\n";

    # Get tests
    print $out &banner('Test Config');
    my @tests = &get_tests($cfgRef);
    my $numTest = @tests;
	print $out '/*! Config for number of tests */' . "\n";
    print $out '#define SM_SCMI_NUM_TEST  '
        . $numTest . 'U' . "\n\n";

    # Loop over tests
    $i = 0;
	print $out '/*! Config data array for tests */' . "\n";
    print $out '#define SM_SCMI_TEST_CONFIG_DATA';
    foreach my $tst (@tests)
    {
        if ($i != 0)
        {
            print $out ',';
        }
        print $out ' \\' . "\n" . '    {' . $tst . '}';
        $i++;
    }
    print $out "\n\n";

    # Check for default channel
    if ($defaultTest eq '<invalid>')
    {
        error_line('missing default test channel', '');
    }

    # Output default channel
    print $out '/*! Default channel for non-agent specific tests */'
        . "\n";
    print $out '#define SM_TEST_DEFAULT_CHN  '
        . $defaultTest . 'U' . "\n";

    # Check for default channel
    if ($mbType eq '<invalid>')
    {
        error_line('no test mailbox', '');
    }

    # Output footer
    print $out &footer('TEST');

    # Close file
    close($out);
}

###############################################################################

sub generate_make
{
    my ($outDir, $cfgRef) = @_;
    my $fileName = 'config.mak';
    my @make = grep(/^MAKE\b/, @$cfgRef);

    # Open file
    open my $out, '>', $outDir . '/' . $fileName
        or die "error: failure to open: $outDir/$fileName, $!";
    if ($verbose)
    {
        my $fn = fileparse($fileName);
        printf("Generating $fn ...\n");
    }

    # Get copyright
    my $cr = &copyright();

    # Convert for makefile
    $cr =~ s/\*\*/##/g;
    $cr =~ s/\/\*\n//g;
    $cr =~ s/\*\/\n//g;

    # Output copyright
    print $out $cr;

	# Output board define
    if ((my $parm = &param($make[0], 'board')) ne '!')
    {
	    print $out 'BOARD ?= ' . $parm . "\n\n";
    }		

	# Output FuSa define
    if ($seenvid != 0)
    {
	    print $out 'USES_FUSA ?= 1' . "\n\n";
    }		

	# Output SoC/board includes
    if ((my $parm = &param($make[0], 'soc')) ne '!')
    {
	    print $out 'include ./devices/' . $parm . '/sm/Makefile' . "\n";
    }		
    if ((my $parm = &param($make[0], 'board')) ne '!')
    {
	    print $out 'include ./boards/$(BOARD)/sm/Makefile' . "\n";
    }		

    # Output conditional includes
    foreach my $key (sort keys %makeInclude)
    {
        print $out 'include ./sm/' . $makeInclude{$key}
            . '/Makefile' . "\n";
    }

	# Output compiler/linker include
    if ((my $parm = &param($make[0], 'build')) ne '!')
    {
	    print $out 'include ./sm/makefiles/' . $parm . '.mak' . "\n";
    }		
    print $out "\n";
    
    # Close file
    close($out);
}

###############################################################################

sub get_perms
{
    my ($cfgRef, $agent) = @_;
    my @perms;

    # Find agent bounds
    my $max = scalar(@{$cfgRef}) - 1;
    my $start = 0;
    my $end = 0;
    my $eof = 0;
    my $nextAgent = $agent + 1;
    for my $i (0 .. $max)
    {
        if (@$cfgRef[$i] =~ /^SCMI_AGENT$agent\b/)
        {
            $start = $i;
        }

        if (@$cfgRef[$i] =~ /^SCMI_AGENT$nextAgent\b/)
        {
            $end = $i;
        }

        if (@$cfgRef[$i] =~ /^EOF/)
        {
            if ($end == 0)
            {
                $end = $i;
            }
        }
    }
    
    # Extract array slice
    my @dat = @$cfgRef[($start+1) .. ($end-1)];

    # Loop over resulting data
    my %foundPerms;
    foreach my $line (@dat)
    {
        # Loop over protocols
        foreach my $proto (@protocols)
        {
            # Get permissions
            if ($line =~ /$proto=(\w+)/)
            {
                my $perm = $1;

                # Get resources
                my $ucProto = uc $proto . '_';
                my @words = split(/ /, $line);
                my @resources = grep(/^[A-Z]+_SM_$ucProto/, @words);

                # Loop over resources
                foreach my $rsrc (@resources)
                {
                    # Save resource permission
                    $foundPerms{$rsrc} = $perm;
                }
            }
        }
    }

    # Loop over found permissions
    foreach my $key (sort keys %foundPerms)
    {
        my $line = '';
        if ($key =~ /[A-Z]+_SM_([A-Z]+)_/)
        {
            $line .= '.' . (lc $1) . 'Perms';
        }
        if ($key =~ /DEV_SM_SYS_0/)
        {
        }
        elsif ($key =~ /DEV_SM_FUSA_0/)
        {
        }
        elsif ($key =~ /DEV_SM_BASE_(\d+)/)
        {
            $line .= '[' . $1 . ']';
        }
        elsif ($key =~ /LMM_(\d+)/)
        {
            $line .= '[' . $1 . ']';
        }
        else
        {
            $line .= '[' . $key . ']';
        }
        $line .= ' = ' . 'SM_SCMI_PERM_' . uc $foundPerms{$key};

        push @perms, $line;
    }

    return sort @perms;
}

###############################################################################

sub get_bctrl
{
    my ($cfgRef) = @_;
    my @bctrl;

    my @dat = grep(/BCTRL_/ || /^LM\d*\b/, @$cfgRef);

    # Loop over resulting data
    my @cpu = ();
    foreach my $line (@dat)
    {
        # Handle LM
        if ($line =~ /^(LM\d*)\b/)
        {
            @cpu = ();
            next;
        }

        # Handle CPU
        if ($line =~ /_SM_CPU_/)
        {
            my @words = split(/ /, $line);

            foreach my $w (@words)
            {
                if ($w =~ /(BCTRL_\w+=\w+)/)
                {
                    push @cpu, $1;
                }
            }
            next;
        }

        # Handle IP
        if ($line =~ /(BCTRL_\w+)=(\w+)/)
        {
            my $reg = $1;
            my $mask = $2;

            # Loop over CPU */
            foreach my $c (@cpu)
            {
                if ($c =~ /(BCTRL_\w+)=(\w+)/)
                {
                    if ($1 eq $reg)
                    {
                        if ($c =~ /BCTRL_([A-Z])_\w+=(\w+)/)
                        {
                            push @bctrl, sprintf("%s: 0x%08X = 0x%08X\n",
                                $1, hex($2), hex($mask));
                        }
                    }
                }
            }
        }
    }

    # Squash common with OR
    my @sctrl = sort @bctrl;
    @bctrl = ();
    my $mix = "";
    my $reg = "";
    my $val = 0;
    foreach my $s (@sctrl)
    {
		if ($s =~ /([A-Z]+): (\w+) = (\w+)/i)
		{
            if (($1 eq $mix) && ($2 eq $reg))
            {
                $val |= hex($3);
            }
            else
            {
                if ($val != 0)
                {
                    push @bctrl, sprintf("%s: %s = 0x%08X\n",
                        $mix, $reg, $val);
                }
                $mix = $1;
                $reg = $2;
                $val = hex($3);
            }    
        }
    }    
    if ($val != 0)
    {
        push @bctrl, sprintf("%s: %s = 0x%08X\n",
            $mix, $reg, $val);
    }

    return sort @bctrl;
}

###############################################################################

sub get_tests
{
    my ($cfgRef) = @_;
    my @tests;

    my @dat = grep(/^CHANNEL\b/ || /\stest\s/, @$cfgRef);

    # Log test data
    &log_array('Test data', \@dat);

    # Loop over resulting data
    my $chn = 0;
    my $a2p = '<invalid>';
    foreach my $line (@dat)
    {
        # Handle channel
        if ($line =~ /^CHANNEL\b/)
        {
            if ($line =~ /type=a2p/)
            {
                $a2p = $chn;
            }
            $chn++;
            next;
        }

        # Loop over protocols
        foreach my $proto (@protocols)
        {
            # Get resources
            my $ucProto = uc $proto . '_';
            my @words = split(/ /, $line);
            my @resources = grep(/^[A-Z]+_SM_$ucProto/, @words);

            # Loop over resources
            foreach my $rsrc (@resources)
            {
                my $test = '';

                if ($a2p eq '<invalid>')
                {
                    error_line('missing SCMI A2P channel', $line);
                }

                $test .= '.testId = TEST_' . uc $proto;
                $test .= ', .channel = ' . $a2p . 'U';
                $test .= ', .rsrc = ';

                if ($rsrc =~ /DEV_SM_SYS_0/)
                {
                    $test .= '0U';
                }
                elsif ($rsrc =~ /DEV_SM_FUSA_0/)
                {
                    $test .= '0U';
                }
                elsif ($rsrc =~ /DEV_SM_BASE_(\d+)/)
                {
                    $test .= $1 . 'U';
                }
                elsif ($rsrc =~ /LMM_(\d+)/)
                {
                    $test .= $1 . 'U';
                }
                else
                {
                    $test .= $rsrc;
                }
                
                push @tests, $test;
            }
        }
    }

    return sort @tests;
}

###############################################################################

sub get_trdc_config
{
    my ($cfgRef) = @_;
	my %hash;

    my @list = grep(/^TRDC_CONFIG_/, @$cfgRef);

    # Loop over list
    foreach my $line (@list)
    {
		my %t;

		if ($line =~ /^TRDC_CONFIG_(\w+) /)
		{
			my $idx = $1;

			# Extract TRDC ndid
	        if ((my $parm = &param($line, 'ndid')) ne '!')
	        {
	            $t{ndid} = $parm;
	        }

			# Extract TRDC nmstr
	        if ((my $parm = &param($line, 'nmstr')) ne '!')
	        {
	            $t{nmstr} = $parm;
	        }

			# Extract TRDC nmbc
	        if ((my $parm = &param($line, 'nmbc')) ne '!')
	        {
	            $t{nmbc} = $parm;
	        }

			# Extract TRDC nmrc
	        if ((my $parm = &param($line, 'nmrc')) ne '!')
	        {
	            $t{nmrc} = $parm;
	        }

	        $hash{$idx} = \%t;
	    }
	}

    return \%hash;
}

###############################################################################

sub get_trdc
{
    my ($cfgRef, $trdcRef) = @_;
    my @rdc;

    my @dat = grep(/\bMDAC_\w+=/ || /\bMBC_\w+=/ || /\bMRC_\w+=/
        || /^LM\d*\b/ || /^DOM\d*\b/ || /^DEBUG\b/, @$cfgRef);

    # Log TRDC info
    &log_array('TRDC info', \@dat);

    # Loop over data
    my $did = '<invalid>';
    my $debugDid = '<invalid>';
    foreach my $line (@dat)
    {
        # Handle DOM
        if ($line =~ /^(DOM\d*)\b/)
        {
            if ((my $parm = &param($line, 'did')) ne '!')
            {
                $did = $parm;
            }
            next;
        }

        # Handle LM
        if ($line =~ /^(LM\d*)\b/)
        {
            if ((my $parm = &param($line, 'did')) ne '!')
            {
                $did = $parm;
            }
            next;
        }

        # Handle DEBUG
        if ($line =~ /^DEBUG\b/)
        {
            if ((my $parm = &param($line, 'did')) ne '!')
            {
                $debugDid = $parm;
            }
            next;
        }

        # Find RDC resources
        my @words = split(/ /, $line);
        my @mdac = grep(/MDAC_\w+=/, @words);
        my @mbc = grep(/MBC_\w+=/, @words);
        my @mrc = grep(/MRC_\w+=/, @words);

        # Loop over MDAC
        foreach my $m (@mdac)
        {
            my $e = $m;

            # Extract MDID
            if ($line =~ /\bmdid=(\w+) /)
            {
	            if ($1 eq 'none')
	            {
	                next;
	            }
	            else
	            {
                	$e .= ' mdid=' . $1;
               	}
            }
            else
            {
				if ($did eq '<invalid>')
				{
	                error_line('missing mdid', $line);
				}

                $e .= ' mdid=' . $did;
            }

            # Extract SA
            if ($line =~ /\bsa=(\w+) /)
            {
                $e .= ' sa=' . $1;
            }
            else
            {
                $e .= ' sa=bypass';
            }

            # Extract PA
            if ($line =~ /\bpa=(\w+) /)
            {
                $e .= ' pa=' . $1;
            }
            else
            {
                $e .= ' pa=bypass';
            }

            # Extract SID
            my $kpa = 1;
            if ($line =~ /\bsid=(\w+) /)
            {
                $e .= ' sid=' . $1;
                $kpa = 0;
            }
            else
            {
                $e .= ' sid=0';
            }

            # Extract KPA
            if ($line =~ /\bkpa=(\w+) /)
            {
                $e .= ' kpa=' . $1;
            }
            else
            {
                $e .= ' kpa=' . $kpa;
            }

            push @rdc, $e . ' ';
        }

        # Loop over MBC
        foreach my $m (@mbc)
        {
            my $e = $m;

            # Extract DID
            if ($line =~ /\bdid=([\w-]+) /)
            {
                $e .= ' did=' . $1;
            }
            else
            {
				if ($did eq '<invalid>')
				{
	                error_line('missing did', $line);
				}

                $e .= ' did=' . $did;
            }

            # Extract memory range */
            if (!($m =~ /\./))
            {
                # Extract base
                if ($line =~ /\borigin=(\w+) /)
                {
                    $e .= ' base=' . $1;
                }
                else
                {
                    error_line('no base address for MBC', $line);
                }

                # Extract beginning
                if ($line =~ /\bbegin=(\w+) /)
                {
                    $e .= ' begin=' . $1;
                }
                else
                {
                    error_line('no beginning address for MBC', $line);
                }

                # Extract end
                if ($line =~ /\bend=(\w+) /)
                {
                    $e .= ' end=' . $1;
                }
                else
                {
                    if ($line =~ /\bsize=(\w+) /)
                    {
                        $e .= ' size=' . $1;
                    }
                    else
                    {
                        error_line('no end address or size for MBC', $line);
                    }
                }

                # Extract block size
                if ($line =~ /\bnblks=(\d+) /)
                {
                    $e .= ' nblks=' . $1;
                }
                else
                {
                    error_line('no number of blocks for MBC', $line);
                }

                # Extract block size
                if ($line =~ /\bblksize=(\w+) /)
                {
                    $e .= ' blksize=' . $1;
                }
                else
                {
                    error_line('no block size for MBC', $line);
                }
            }

            # Extract permissions
            if ($line =~ /\bperm=(\w+) /)
            {
                $e .= ' perm=' . $1;
            }
            else
            {
                error_line('no perms for MBC', $line);
            }

            push @rdc, $e . ' ';
        }

        # Loop over MRC
        foreach my $m (@mrc)
        {
            my $e = $m;

            # Extract DID
            if ($line =~ /\bdid=([\w-]+) /)
            {
                $e .= ' did=' . $1;
            }
            else
            {
                $e .= ' did=' . $did;
            }

            # Extract start
            if ($line =~ /\bbegin=(\w+) /)
            {
                $e .= ' begin=' . $1;
            }
            else
            {
                error_line('no beginning address for MRC', $line);
            }

            # Extract end
            if ($line =~ /\bend=(\w+) /)
            {
                $e .= ' end=' . $1;
            }
            else
            {
                if ($line =~ /\bsize=(\w+) /)
                {
                    $e .= ' size=' . $1;
                }
                else
                {
                    error_line('no end address or size for MRC', $line);
                }
            }

            # Extract number of regions
            if ($line =~ /\bnrgns=(\d+) /)
            {
                $e .= ' nrgns=' . $1;
            }
            else
            {
                error_line('no number of regions for MRC', $line);
            }

            # Extract permissions
            if ($line =~ /\bperm=(\w+) /)
            {
                $e .= ' perm=' . $1;
            }
            else
            {
                error_line('no perms for MRC', $line);
            }

            # Extract big
            if ($line =~ /\bbig=(\w+) /)
            {
                $e .= ' big=' . $1;
            }
            else
            {
                $e .= ' big=0';
            }

            push @rdc, $e . ' ';
        }
    }

    # Log TRDC data
    &log_array('Raw TRDC data', \@rdc);

    # Handle debug
    if ($debugDid ne '<invalid>')
    {
        my @debugLines;
        foreach my $m (@rdc)
        {
            if (($m =~ /\bM[BR]C_\w+=/)
                && ($m =~ /\bdid=\d+ /))
            {
                my $a = $m;
                $a =~ s/\bdid=\d+/did=$debugDid/g;
                $a =~ s/\bperm=\w+/perm=0x6600/g;
                push @debugLines, $a;            
            }
        }
        push @rdc, @debugLines;
    }

    # Convert hex values
    foreach my $m (@rdc)
    {
        while ($m =~ /(\w+)=(0x\w+) /)
        {
            my $parm = $1;
            my $num = hex($2);
            $m =~ s/$parm=$2/$parm=$num/g;
        }
    }

    # Convert non-numeric values
    foreach my $m (@rdc)
    {
        while ($m =~ /(\w+)=(\d+)([KMG])/)
        {
            my $parm = $1;
            my $val = $2;
            my $post = $3;
            my $num = $val * 1024;

            $m =~ s/$parm=$val$post/$parm=$num/g;      
        }
    }    

    # Convert end to a size
    foreach my $m (@rdc)
    {
        if (($m =~ /\bend=(\w+) /) && !($m =~ /\bsize=/))
        {
            my $end = $1;
            $m =~ /\bbegin=(\w+) /;
            my $start = $1;

            my $size = $end - $start + 1;
            
            $m .= 'size=' . $size . ' ';
        }
    }

    # Convert range to blocks for MBC
    foreach my $m (@rdc)
    {
        if ($m =~ /\b(MBC_\w+=\d+) /)
        {
			# Extract parms
			my $mbc = $1;
			my $base = &param($m, 'base');
			my $begin = &param($m, 'begin');
			my $size = &param($m, 'size');
			my $blksize = &param($m, 'blksize');
			my $nblks = &param($m, 'nblks');

			# Calculate blocks
			my $first = ($begin - $base) / $blksize;
			my $last = $first + ($size / $blksize) - 1;

			# Check range
			if ($first < 0)
			{
				error_line('invalid address beginning ' . $mbc, $m);
			}
			if ($last >= $nblks)
			{
				error_line('invalid address end/size ' . $mbc, $m);
			}

			# Swap in blocks
			if ($first == $last)
			{
				$m =~ s/\b(MBC_\w+=\d+) /$1\.$first /g;
			}
			else
			{
				$m =~ s/\b(MBC_\w+=\d+) /$1\.$first-$last /g;
			}

			# Remove range parameters
			$m =~ s/\bbase=\w+ //g;
			$m =~ s/\bbegin=\w+ //g;
			$m =~ s/\bend=\w+ //g;
			$m =~ s/\bnblks=\w+ //g;
			$m =~ s/\bblksize=\w+ //g;
			$m =~ s/\bsize=\w+ //g;
		}
	}    

    # Expand MDAC range
    foreach my $m (@rdc)
    {
        if ($m =~ /\bMDAC_\w+=(\d+)-(\d+) /)
        {
            my $f = $1;
            my $l = $2;

            for (my $n = $f; $n < $l; $n++)
            {
                $a = $m;
                $a =~ s/\bMDAC_(\w+)=$f-$l/MDAC_$1=$n/g;
                push @rdc, $a;
            }            
            $m =~ s/\bMDAC_(\w+)=$f-$l/MDAC_$1=$l/g;
        }
    }

    # Expand DID
    foreach my $m (@rdc)
    {
        while ($m =~ /\bdid=(\d+)-(\d+) /)
        {
            my $f = $1;
            my $l = $2;

            for (my $n = $f; $n < $l; $n++)
            {
                my $a = $m;
                $a =~ s/\bdid=$f-$l/did=$n/g;
                push @rdc, $a;
            }            
            $m =~ s/\bdid=$f-$l/did=$l/g;
        }
    }

    # Expand block range
    foreach my $m (@rdc)
    {
        if ($m =~ /\b(MBC_\w+=\d+\.)(\d+)-(\d+) /)
        {
            my $b = $1;
            my $f = $2;
            my $l = $3;

            for (my $n = $f; $n < $l; $n++)
            {
                $a = $m;
                $a =~ s/\b$b$f-$l/$b$n/g;
                push @rdc, $a;
            }            
            $m =~ s/\b$b$f-$l/$b$l/g;
        }
    }

	# Convert to TRDC register list
    foreach my $m (@rdc)
    {
        # Handle MDAC
        if ($m =~ /MDAC_([A-Z]+)(\d+)(C*)=(\d+) mdid=(\d+) sa=(\w+) pa=(\w+) sid=(\d+) kpa=(\d+)/)
        {
			my $dfmt;
			my $data = (1 << 31) | $5;

			$data |= ($8 << 22);
			$data |= ($9 << 28);

			if ($3 eq 'C')
			{
				$data |= (&sapa($6) << 14);
				$dfmt = 0;
			}
			else
			{
				$data |= (&sapa($6) << 6);
				$data |= (&sapa($7) << 4);
				$dfmt = 1;
			}
			$data |= ($dfmt << 29);

	        $m = sprintf("TRDC%s_MDA_W%d_%d_DFMT%d = 0x%08X,",
	        	$1, $4, $2, $dfmt, $data);

            next;
        }

        # Handle MBC
        if ($m =~ /MBC_([A-Z]+)(\d+)=(\d+).(\d+) did=(\d+) perm=(\d+) /)
        {
			my $w = $4 / 8;
			my $n = $4 % 8;
	        $m = sprintf("TRDC%s_MBC%d_DOM%02d_MEM%d_BLK_CFG_W%02d[%d] = %d",
	        	$1, $2, $5, $3, $w, $n, $6);
			next;
	    }

        # Handle MRC
        if ($m =~ /^MRC_([A-Z]+)(\d+)=(\d+) did=(\d+) begin=(\d+) end=(\d+) nrgns=(\d+) perm=(\d+) big=(\d+)/)
        {
            my $w0;
            my $w1;
            
            if ($9 == 1)
            {
			    $w0 = ($5 >> 4) & 0xFFFFFC00;
			    $w1 = (($6 >> 4) & 0xFFFFFC00) | 1;
            }
            else
            {
			    $w0 = $5 & 0xFFFFC000;
			    $w1 = ($6 & 0xFFFFC000) | 1;
			}

			my $perm = $8;
		
			$m = sprintf("TRDC%s_MRC%d_DOM%d_RGD%d %d, %d = %d, %d",
				$1, $2, $4, $3, $w0, $w1, $perm, $7);
            next;
        }
		
	}

	# Determine MBC GLBAC and substitute
	@rdc = sort @rdc;
	my @glbac = (0x0000, 0x6666, 0x7777);
	my $curr_mbc = '';
    foreach my $m (@rdc)
    {
        # Handle MBC
        if ($m =~ /(TRDC[A-Z]+_MBC\d+)_DOM/)
        {
			my $mbc = $1;

			$m =~ /(TRDC[A-Z]+_MBC\d+_DOM\d+_MEM\d+_BLK_CFG_W\d+)\[(\d+)\] = (\d+)/;
			my $elm = $1;
			my $b = $2;
			my $perm = $3;

			# New MBC
			if ($curr_mbc ne $mbc)
			{
				# Save GLBAC
				if ($curr_mbc ne '')
				{
					for my $i (0 .. $#glbac)
					{
						my $g = sprintf("%s_MEMN_GLBAC%d = 0x%04X",
							$curr_mbc, $i, $glbac[$i]);
						push @rdc, $g;
					}
				}

				@glbac = (0x0000, 0x6666, 0x7777);
				$curr_mbc = $mbc;
			}

			# Find match
			my $match = -1;
			for my $i (0 .. $#glbac)
			{
				if ($glbac[$i] == $perm)
				{
					$match = $i;
					last;
				}
			}			

			# Not found
			if ($match == -1)
			{
				$match = $#glbac + 1;

				# Check for overflow
				if ($match == 8)
				{
					error_line('too many GLBAC ' . $mbc, '');
				}

				push @glbac, $perm;
			}

            # Set NSE
			if (($perm & 0x00FF) != 0)
			{
				$match |= 0x8;
			}

			# Replace
			$m =~ s/$elm\[$b\] = $perm/$elm\[$b\] = $match/;
	    }
	}	

	# Save last MBC GLBAC
	if ($curr_mbc ne '')
	{
		for my $i (0 .. $#glbac)
		{
			my $g = sprintf("%s_MEMN_GLBAC%d = 0x%04X",
				$curr_mbc, $i, $glbac[$i]);
			push @rdc, $g;
		}
	}

	# Determine MRC GLBAC and substitute
	@glbac = ();
	my $curr_mrc = '';
	my $rgd = 0;
	my $curr_rgd = '';
	my $old_elm = '';
	my $old_rgn = 4;
    foreach my $m (@rdc)
    {
        # Handle MRC region
        if ($m =~ /(TRDC[A-Z]+_MRC\d+_DOM\d+_RGD)\d+ (\d+), (\d+) = (\d+), (\d+)/)
        {
			my $elm = $1;
			my $w0 = $2;
			my $w1 = $3;
			my $perm = $4;
			my $rgn = $5;

            if ($w1 != 0)
            {
    			# New MRC
    			if ($curr_rgd ne $elm)
    			{
					my $clr = 4;
					if ($old_rgn < $clr)
					{
						$clr = $old_rgn;
					}

                    while (($old_elm ne '') && ($rgd < $clr))
                    {
                        my $new_m = sprintf("%s%02d %d, %d = %d", $old_elm, $rgd,
                            0, 0, 0);

                        push @rdc, $new_m;
                        $rgd++;
                    }

    				$rgd = 0;
    				$curr_rgd = $elm;
    			}

    			# Check for overflow
    			if ($rgd >= 16)
    			{
    				error_line('too many regions ' . $elm, '');
    			}

				if ($perm != 0)
				{
    				$m = sprintf("%s%02d %d, %d = %d", $elm, $rgd, $w0, $w1, $perm);
    				$rgd++;
    			}
    			else
    			{
    				$m = '';
    			}

                $old_elm = $elm;
                $old_rgn = $rgn;
    		}
        }

        # Handle MRC perm
        if ($m =~ /(TRDC[A-Z]+_MRC\d+)_DOM/)
        {
			my $mrc = $1;

			$m =~ /(TRDC[A-Z]+_MRC\d+_DOM\d+_RGD\d+) (\d+), (\d+) = (\d+)/;
			my $elm = $1;
			my $w0 = $2;
			my $w1 = $3;
			my $perm = $4;

			# New MRC
			if ($curr_mrc ne $mrc)
			{
				# Save GLBAC
				if ($curr_mrc ne '')
				{
					for my $i (0 .. $#glbac)
					{
						my $g = sprintf("%s_GLBAC%d = 0x%04X",
							$curr_mrc, $i, $glbac[$i]);
						push @rdc, $g;
					}
				}

				@glbac = ();
				$curr_mrc = $mrc;
			}

            if (($w1 != 0) && ($perm != 0))
            {
    			# Find match
    			my $match = -1;
    			for my $i (0 .. $#glbac)
    			{
    				if ($glbac[$i] == $perm)
    				{
    					$match = $i;
    					last;
    				}
    			}			

    			# Not found
    			if ($match == -1)
    			{
    				$match = $#glbac + 1;

    				# Check for overflow
    				if ($match == 8)
    				{
    					error_line('too many GLBAC ' . $mrc, '');
    				}

    				push @glbac, $perm;
    			}

                # Set NSE
    			if (($perm & 0x00FF) != 0)
    			{
    				$w1 |= 0x10;
    			}

    			# Replace
    			$w0 |= $match;
    	    }

            # Save
    	    $m = sprintf("%s = 0x%08X, 0x%08X", $elm, $w0, $w1);
	    }
	}	

	# Save last MRC GLBAC
	if ($curr_mrc ne '')
	{
		for my $i (0 .. $#glbac)
		{
			my $g = sprintf("%s_GLBAC%d = 0x%04X",
				$curr_mrc, $i, $glbac[$i]);
			push @rdc, $g;
		}
	}

	# Collapse MBC into registers
	my @reg;
	my %h;
	my $w = 0;
    foreach my $m (@rdc)
    {
        # Handle MBC
        if ($m =~ /(TRDC[A-Z]+_MBC\d+_DOM\d+_MEM\d+_BLK_CFG_W\d+)\[(\d+)\] = (\d+)/)
        {
			my $elm = $1;
			my $b = $2;
			my $val = $3;
			
			$h{$elm} |= ($3 << ($b * 4));
		}
		else
		{
			push @reg, $m;
		}
	}
    foreach my $key (keys %h)
    {
		my $u = sprintf("%s = 0x%08X", $key, $h{$key});

		push @reg, $u;
    }

    return sort @reg;
}

###############################################################################

sub convert_trdc
{
    my ($cfgRef, $trdcRef) = @_;
    my @avp;

    # Loop over the array
    foreach my $t (@$cfgRef)
    {
		# TRDCn_MDA_Wn_n_DFMTn  
		if ($t =~ /TRDC([A-Z]+)_MDA_W(\d+)_(\d+)_DFMT(\d+) = (\w+)/)
		{
			my $idx = $1;
			my $w = $2;
			my $mda = $3;
			my $dfmt = $4;
			my $val = $5;
			
			# Calculate address
			my $addr = 0x800 + (0x20 * $mda) + (0x4 * $w);

			push @avp, sprintf("%s: 0x%08x = %s", uc $idx, $addr, $val);
		}
		# Handle TRDCn_MBCn_MEMN_GLBACn  
		elsif ($t =~ /TRDC([A-Z]+)_MBC(\d+)_MEMN_GLBAC(\d+) = (\w+)/)
		{
			my $idx = $1;
			my $mbc = $2;
			my $glbac = $3;
			my $val = $4;
			
			# Calculate address
			my $addr = 0x10020 + (0x2000 * $mbc) + (0x4 * $glbac);

			# Put first gblac at the end to allow hop
			if ($glbac eq '0')
			{
				push @avp, sprintf("%s: 0x%08x = %s", lc $idx, $addr, $val);
			}
			else
			{
				push @avp, sprintf("%s: 0x%08x = %s", uc $idx, $addr, $val);
			}
		}
		# Handle TRDCn_MBCn_DOMn_MEMn_BLK_CFG_Wn  
		elsif ($t =~ /TRDC([A-Z]+)_MBC(\d+)_DOM(\d+)_MEM(\d+)_BLK_CFG_W(\d+) = (\w+)/)
		{
			my $idx = $1;
			my $mbc = $2;
			my $dom = $3;
			my $mem = $4;
			my $w = $5;
			my $val = $6;
			
			# Calculate address
			my $addr = 0x10040 + (0x2000 * $mbc) + (0x200 * $dom)
				+ (0x4 * $w);
			if ($mem > 0)
			{
				$addr += 0x140 + (0x28 * ($mem - 1));
				
			}

			push @avp, sprintf("%s: 0x%08x = %s", uc $idx, $addr, $val);
		}
		# Handle TRDCn_MRCn_GLBACn  
		elsif ($t =~ /TRDC([A-Z]+)_MRC(\d+)_GLBAC(\d+) = (\w+)/)
		{
			my $idx = $1;
			my $mrc = $2;
			my $glbac = $3;
			my $val = $4;
			
			# Calculate address
			my $nmbc = $trdcRef->{$idx}->{nmbc};
			my $addr = 0x10020 + (0x2000 * $nmbc) + (0x1000 * $mrc)
				+ (0x4 * $glbac);

			if ($glbac eq '0')
			{
				push @avp, sprintf("%s: 0x%08x = %s", lc $idx, $addr, $val);
			}
			else
			{
				push @avp, sprintf("%s: 0x%08x = %s", uc $idx, $addr, $val);
			}
		}
		# Handle TRDCn_MRCn_DOMn_RGDn  
		elsif ($t =~ /TRDC([A-Z]+)_MRC(\d+)_DOM(\d+)_RGD(\d+) = (\w+), (\w+)/)
		{
			my $idx = $1;
			my $mrc = $2;
			my $dom = $3;
			my $rgd = $4;
			my $val1 = $5;
			my $val2 = $6;
			
			# Calculate address
			my $nmbc = $trdcRef->{$idx}->{nmbc};
			my $addr = 0x10040 + (0x2000 * $nmbc) + (0x1000 * $mrc)
				+ (0x8 * $rgd) + (0x100 * $dom);

			if ($val2 ne '0x00000000')
			{
				push @avp, sprintf("%s: 0x%08x = %s", uc $idx, $addr, $val1);
			}
			push @avp, sprintf("%s: 0x%08x = %s", uc $idx, $addr + 4, $val2);
		}
		elsif ($t eq '')
		{
		}
		else
		{
           	error_line('unknown TRDC register', $t);
		}
	}

	return sort @avp;
}

###############################################################################

sub compress_data
{
    my (@avpRef) = @_;
    my $rtn = '';

	# Loop over each line
    foreach my $line (@avpRef)
    {
		if ($line =~ /([A-Z]+): (\w+) = (\w+)/i)
		{
			my $data = hex($3);

			if ($data == 0)
			{
				$rtn .= '        SM_CFG_Z1(';
				$rtn .= $2 . 'U), \\';
			}
			else
			{
				$rtn .= '        SM_CFG_W1(';
				$rtn .= $2 . 'U), ' . $3 . 'U, \\';
			}
			$rtn .= "\n";
		}
	}

	return $rtn;
}

###############################################################################

sub sapa
{
    my ($name) = @_;

	if ($name eq 'secure')
	{
		return 0;
	}
	elsif  ($name eq 'user')
	{
		return 0;
	}
	elsif  ($name eq 'bypass')
	{
		return 2;
	}
	
	return 1;
}

###############################################################################

sub param
{
    my ($line, $name) = @_;

    # Find pair name=value
    if ($line =~ /\b$name=[\w\-\.\/"\|]+\s/)
    {
        $line =~ /\b$name=([\w\-\.\/"\|]+)\s/;

        return $1;
    }

    # Return not found indicator
    return '!';
}

###############################################################################

sub header
{
    my ($mod, $comment) = @_;
    my $rtn = '';

    # Output copyright
    $rtn .= &copyright();

    # Output doxygen banner
    $rtn .= '/*========================================='
        .   '=================================*/' . "\n";
    $rtn .= '/*!' . "\n";
    $rtn .= ' * @addtogroup ' . $config_name . "\n";
    $rtn .= ' * @{' . "\n";
    $rtn .= ' *' . "\n";
    $rtn .= ' * @file' . "\n";
    $rtn .= ' * @brief' . "\n";
    $rtn .= ' *' . "\n";
    $rtn .= ' * Header file containing coniguration info for the '
        . $comment . '.' . "\n";
    $rtn .= ' */' . "\n";
    $rtn .= '/*========================================='
        .   '=================================*/' . "\n\n";

    # Output header guard
    $rtn .= '#ifndef CONFIG_' . $mod . '_H' . "\n";
    $rtn .= '#define CONFIG_' . $mod . '_H' . "\n\n";

    return $rtn;
}

###############################################################################

sub footer
{
    my ($mod) = @_;
    my $rtn = '';

    # Add footer inc. header guard
    $rtn .= "\n";
    $rtn .= '#endif /* CONFIG_' . $mod . '_H */' . "\n\n";
    $rtn .= '/** @} */' . "\n\n";

    return $rtn;
}

###############################################################################

sub banner
{
    my ($line) = @_;
    my $rtn = '';

    # Add banner with text line
    $rtn .= '/*-------------------------------------'
        .'-------------------------------------*/' . "\n";
    $rtn .= '/* ' . sprintf("%*s ", -71, $line) . ' */' . "\n";
    $rtn .= '/*-------------------------------------'
        .'-------------------------------------*/' . "\n\n";

    return $rtn;
}

###############################################################################

sub copyright
{
    my $rtn = '';

    # Add copyright text
    $rtn .= '/*' . "\n";
    $rtn .= '** ###################################################################' . "\n";
    $rtn .= '**' . "\n";
    $rtn .= '** Copyright 2023-2024 NXP' . "\n";
    $rtn .= '**' . "\n";
    $rtn .= '** Redistribution and use in source and binary forms, with or without modification,' . "\n";
    $rtn .= '** are permitted provided that the following conditions are met:' . "\n";
    $rtn .= '**' . "\n";
    $rtn .= '** o Redistributions of source code must retain the above copyright notice, this list' . "\n";
    $rtn .= '**   of conditions and the following disclaimer.' . "\n";
    $rtn .= '**' . "\n";
    $rtn .= '** o Redistributions in binary form must reproduce the above copyright notice, this' . "\n";
    $rtn .= '**   list of conditions and the following disclaimer in the documentation and/or' . "\n";
    $rtn .= '**   other materials provided with the distribution.' . "\n";
    $rtn .= '**' . "\n";
    $rtn .= '** o Neither the name of the copyright holder nor the names of its' . "\n";
    $rtn .= '**   contributors may be used to endorse or promote products derived from this' . "\n";
    $rtn .= '**   software without specific prior written permission.' . "\n";
    $rtn .= '**' . "\n";
    $rtn .= '** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND' . "\n";
    $rtn .= '** ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED' . "\n";
    $rtn .= '** WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE' . "\n";
    $rtn .= '** DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR' . "\n";
    $rtn .= '** ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES' . "\n";
    $rtn .= '** (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;' . "\n";
    $rtn .= '** LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON' . "\n";
    $rtn .= '** ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT' . "\n";
    $rtn .= '** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS' . "\n";
    $rtn .= '** SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.' . "\n";
    $rtn .= '**' . "\n";
    $rtn .= '**' . "\n";
    $rtn .= '** ###################################################################' . "\n";
    $rtn .= '*/' . "\n\n";

    return $rtn;
}

###############################################################################

sub startstop
{
    my ($num, $ssRef) = @_;
    my $rtn = '';

	if ($num > 0)
	{
	    foreach my $s (@$ssRef)
	    {
			$rtn .= ' \\' . "\n";

			$rtn .= '    {';

	        if ((my $parm = &param($s, 'lm')) ne '!')
	        {
	        	$rtn .= '.lmId = ' . $parm . 'U,';
	        }

	        if ((my $parm = &param($s, 'msel')) ne '!')
	        {
	        	$rtn .= ' .mSel = ' . $parm . 'U,';
	        }

	        if ((my $parm = &param($s, 'ss')) ne '!')
	        {
	        	$rtn .= ' .ss = ' . $parm . ',';
	        }

	        if ((my $parm = &param($s, 'rsrc')) ne '!')
	        {
	        	$rtn .= ' .rsrc = ' . $parm;
	        }

	        if ((my $parm = &param($s, 'arg')) ne '!')
	        {
        		my @words = split(/\|/, $parm);

				shift @words;

				if (@words > 0)
				{
					$rtn .= ', '  . '\\' . "\n";
					$rtn .= '     .numArg = ' . @words . ',';
				}

				for my $i (0 .. $#words)
			    {
		        	$rtn .= ' .arg[' . $i . '] = ' . $words[$i] . 'U,';
				}				
	        }

	        $rtn .= '},';
		}
	}

	$rtn .= "\n";
    return $rtn;
}

###############################################################################

sub error_line
{
    my ($msg, $line) = @_;

    # Print file/line
    if ((my $parm = &param($line, 'filename')) ne '!')
    {
        print STDERR $parm . ':';
    }
    if ((my $parm = &param($line, 'line')) ne '!')
    {
        print STDERR $parm . ': ';
    }

    # Print error message
    print STDERR 'error: ' . $msg . "\n";
    exit;
}

###############################################################################

sub get_define
{
	my ($str, $aRef) = @_;

    my @define = grep(/^$str /, @$aRef);

	if (@define)
	{
        my @words = split(/ /, $define[0]);

		if ($words[1])
		{
			return $words[1];
		}
	}
}

