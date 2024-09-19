#!/usr/bin/perl
## ###################################################################
##
## Copyright 2024 NXP
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
use List::Util qw(max);

# Subroutines
sub load_config_files;
sub load_file;
sub generate_lm;
sub generate_rsrc;
sub generate_pin;
sub generate_mem;
sub param;
sub get_define;
sub print_table;

my %args;

# Parse command line
getopts('hi:', \%args);
my $help = $args{h};
my $inputFile = $args{i};
my $cfgName = basename($inputFile, '.cfg');

# Check for required arguments
if ($help || (not defined $inputFile))
{
    my $cmd = fileparse($0);

    print "Usage: $cmd [OPTIONS]...\n";
    print "Dump info from SM configuration files.\n\n";
    print "  -i  specify input file\n";
    print "  -h  display this help and exit\n\n";
    print "The input configuration file is loaded, processed, and\n";
    print "information written to STDOUT\n";
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

# Load config files
my @cfg = &load_config_files($inputFile); 

# Print banner
print $cfgName . "\n";
print '=' x (length $cfgName) . "\n\n";

# Generate LM list
&generate_lm(\@cfg);

# Generate resource list
&generate_rsrc(\@cfg);

# Generate pin list
&generate_pin(\@cfg);

# Generate memory list
&generate_mem(\@cfg);

###############################################################################

sub load_config_files
{
    my ($cfgFile) = @_;

    # Load input file
    my @cfg = &load_file($cfgFile);

    # Remove duplicate words
    foreach (@cfg)
    {
        my (%before, @words, @new);

        @words = split(/ /, $_);
        @new = grep { ! $before{$_}++ } @words;
        $_ = join ' ', @new;
    }

    # Cleanup
    @cfg = grep(!/^NOTIFY:/, @cfg);
    @cfg = grep(!/^GET:/, @cfg);
    @cfg = grep(!/^SET:/, @cfg);
    @cfg = grep(!/^PRIV:/, @cfg);
    @cfg = grep(!/^ALL:/, @cfg);
    @cfg = grep(!/^READONLY:/, @cfg);
    @cfg = grep(!/^CONTROL:/, @cfg);
    @cfg = grep(!/^DATA:/, @cfg);
    @cfg = grep(!/^EXEC:/, @cfg);
    @cfg = grep(!/^OWNER:/, @cfg);
    @cfg = grep(!/^DFMT0:/, @cfg);
    @cfg = grep(!/^DFMT1:/, @cfg);
    @cfg = grep(!/^TEST_MU:/, @cfg);
    @cfg = grep(!/^ACCESS:/, @cfg);
    @cfg = grep(!/^ALL_RO:/, @cfg);
    @cfg = grep(!/^PD_/, @cfg);
    @cfg = grep(!/perm=0/, @cfg);

	# Append
    push @cfg, 'FUSA:';
    push @cfg, 'SYS:';

    # Remove test
    s/test//g for @cfg;

    # Remove leading/trailing spaces
    s/^\s+|\s+$//g for @cfg;

    # Remove extra spaces
    s/\s+/ /g for @cfg;

    # Append end marker
    push @cfg, 'EOF';

    # Append space at end of every line
    s/$/ /g for @cfg;

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

            push @contents, $line;
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

sub generate_lm
{
    my ($cfgRef) = @_;
    my @list = grep(!/^[A-Z0-9_]+: /, @$cfgRef);
    my @table;

    # Loop over LM
	my @clients = grep(/^LM[0-9]+ /, @list);
	my $heading = 'Parameter|';
	my $name = 'Name|';
	my $did = 'Domain ID|';
	my $boot = 'Boot Order|';
	my $safe = 'Safety Type|';
    foreach my $l (@clients)
	{
        if ($l =~ /^(LM[0-9]+) /)
        {
			$heading .= $1 . '|';

		    if ((my $parm = &param($l, 'name')) ne '!')
		    {
            	$parm =~ s/\"//g;
				$name .= $parm . '|';
		    }
		    else
		    {
				$name .= ' |';
		    }

		    if ((my $parm = &param($l, 'did')) ne '!')
		    {
            	$parm =~ s/\"//g;
				$did .= $parm . '|';
		    }
		    else
		    {
				$did .= ' |';
		    }

		    if ((my $parm = &param($l, 'boot')) ne '!')
		    {
            	$parm =~ s/\"//g;
				$boot .= $parm . '|';
		    }
		    else
		    {
				$boot .= ' |';
		    }

		    if ((my $parm = &param($l, 'safe')) ne '!')
		    {
            	$parm =~ s/\"//g;
				$safe .= uc $parm . '|';
		    }
		    else
		    {
				$safe .= ' |';
		    }
        }
	}

	my $agents = 'Agents';
	my $count = 0;
	@clients = grep(/^[A-Z]+_AGENT[0-9]+ / || /^LM[0-9]+ /, @list);
    foreach my $l (@clients)
	{
        if ($l =~ /^(LM[0-9]+) /)
        {
            $agents .= ' |';
            $count = 0;
        }

        if ($l =~ /^[A-Z]+_(AGENT[0-9]+) /)
        {
			my $aName = $1;

            if ($count > 0)
            {
				$agents .= ', ';
            }
			$count++;

		    if ((my $parm = &param($l, 'name')) ne '!')
		    {
            	$parm =~ s/\"//g;
				$agents .= $parm;
		    }
		    else
		    {
				$agents = $agents . $aName;
		    }
        }
    }
    $agents .= '|';

    # Build table
    push @table, $heading;
    push @table, $name;
    push @table, $did;
    push @table, $boot;
    push @table, $safe;
    push @table, $agents;

    # Print banner
    print 'LM Info' . "\n";
    print '-------' . "\n\n";

	print_table(\@table);
	print "\n";
}

###############################################################################

sub generate_rsrc
{
    my ($cfgRef) = @_;
    my @rsrc = grep(/^[A-Z0-9_]+: /, @$cfgRef);
    my @list = grep(!/^[A-Z0-9_]+: /, @$cfgRef);
    my @table;

	# Filter
	@rsrc = sort @rsrc;
    @rsrc = grep(!/nrgns/, @rsrc);
    @rsrc = grep(!/nblks/, @rsrc);

	# Start heading
	my $heading = 'Resource|DOM|';

    # Loop over agents
	my @clients = grep(/^[A-Z]+_AGENT[0-9]+ / || /^LM0 /, @list);
    foreach my $l (@clients)
	{
        if ($l =~ /^LM0 /)
        {
			$heading = $heading . 'SM' . '|';
        }
        if ($l =~ /^[A-Z]+_(AGENT[0-9]+) /)
        {
			my $aName = $1;

		    if ((my $parm = &param($l, 'name')) ne '!')
		    {
            	$parm =~ s/\"//g;
				$heading = $heading . $parm . '|';
		    }
		    else
		    {
				$heading = $heading . $aName . '|';
		    }
        }
	}
    push @table, $heading;

    # Loop over resources
    my $dom = '';
    foreach my $r (@rsrc)
    {
        if ($r =~ /^([A-Z0-9_]+): /)
        {
			my $name = $1;
			my $row = $name . '|';

			my $p = '';
			my @clientRsrc = grep(/^LM0 / || /^[A-Z]+_AGENT[0-9]+ /
				|| /^DOM[0-9]+ / || /^$name /, @list);

		    foreach my $l (@clientRsrc)
			{
		        if ($l =~ /^DOM([0-9]+) /)
		        {
		        	$dom = $1;
		        }
		        elsif ($l =~ /^LM0 /)
		        {
					$row = $row . $p . ' |';
                    $p = '';
                    $dom = '';
		        }
		        elsif ($l =~ /^[A-Z]+_AGENT[0-9]+ /)
		        {
					$row = $row . $p . ' |';
                    $p = '';
                    $dom = '';
		        }
		        else
		        {
        			my @words = split(/ /, $l);

                    if ($dom ne '')
                    {
                        $p = $dom;
                    }
                    else
                    {
						if ($words[1])
						{
                        	$p = $words[1];
                        }
                        else
                        {
                        	$p = ' ';
                        }	
                    }
		        }
			}
			$row = $row . $p . ' |';

    		push @table, $row;
        }
   	}

    # Print banner
    print 'Resources' . "\n";
    print '---------' . "\n\n";

	print_table(\@table);
	print "\n";
}

###############################################################################

sub generate_pin
{
    my ($cfgRef) = @_;
}

###############################################################################

sub generate_mem
{
    my ($cfgRef) = @_;
    my @mem = grep(/^[A-Z0-9_]+ /, @$cfgRef);
    my @list = grep(!/^[A-Z0-9_]+: /, @$cfgRef);
    my @table;

	# Filter
    @mem = grep(/^LM0 / || /^[A-Z]+_AGENT[0-9]+ /  || /^DOM[0-9]+ /
    	|| /begin=/, @mem);
    @mem = grep(!/end=0x0 /, @mem);

	# Process data
	my @newMem;
	my $owner = '';
    foreach my $l (@mem)
	{
        if ($l =~ /^(DOM[0-9]+) /)
        {
			$owner = $1;
        }
        elsif ($l =~ /^LM0 /)
        {
			$owner = 'LM0';
        }
        elsif ($l =~ /^[A-Z]+_(AGENT[0-9]+) /)
        {
			$owner = $1;
        }
		elsif ((my $begin = &param($l, 'begin')) ne '!')
	    {
			$begin = hex($begin);
			my $end;
	        my @words = split(/ /, $l);

		    if ((my $parm = &param($l, 'end')) ne '!')
		    {
				$end = hex($parm);
		    }
		    if ((my $parm = &param($l, 'size')) ne '!')
		    {
		        if ($parm =~ /(\d+)([KMG])/)
		        {
		            my $val = $1;
		            my $post = $2;
		            my $num;

					if ($post eq 'K')
					{
			            $end = $begin + ($val * 1024) - 1;
					}
					elsif ($post eq 'M')
					{
			            $end = $begin + ($val * 1024 * 1024) - 1;
					}
					else
					{
			            $end = $begin + ($val * 1024 * 1024 * 1024) - 1;
					}
				}
		    }

			my $line = sprintf("0x%09X-0x%09X %s %s=%s", $begin,
				$end, $words[0], $owner, $words[1]);	


	   		push @newMem, $line . ' ';
	    }
	}
	@mem = sort @newMem;

	# Start heading
	my $heading = 'Address|Mem|DOM|';

    # Loop over agents
    my $numAgents = 0;
	my @clients = grep(/^[A-Z]+_AGENT[0-9]+ / || /^LM0 /, @list);
    foreach my $l (@clients)
	{
        if ($l =~ /^LM0 /)
        {
			$heading = $heading . 'SM' . '|';
        }
        if ($l =~ /^[A-Z]+_(AGENT[0-9]+) /)
        {
			my $aName = $1;

		    if ((my $parm = &param($l, 'name')) ne '!')
		    {
            	$parm =~ s/\"//g;
				$heading = $heading . $parm . '|';
		    }
		    else
		    {
				$heading = $heading . $aName . '|';
		    }

		    $numAgents++;
        }
	}
    push @table, $heading;

#	print Dumper(@mem);

    # Loop over memory regions
    foreach my $m (@mem)
	{
        my @words = split(/ /, $m);
        my $row = $words[0] . '|' . $words[1] . '|';

		shift @words;
		shift @words;

		# Search for domains
		my $dom = ' ';
	    foreach my $w (@words)
		{
	        if ($w =~ /^DOM([0-9]+)=/)
	        {
				if ($dom eq ' ')
				{
					$dom = $1;
				}
				else
				{
					$dom = $dom . ',' . $1;
				}
	        }		
		}
		$row = $row . $dom . '|';

		# Search for LM0
	    if ((my $parm = &param($m, 'LM0')) ne '!')
	    {
			$row = $row . $parm;
	    }
		$row = $row . ' |';

		for (my $i=0; $i < $numAgents; $i++)
		{
		    if ((my $parm = &param($m, 'AGENT' . $i)) ne '!')
		    {
				$row = $row . $parm . '|';
		    }
		    else
		    {
				$row = $row . ' |';
			}
		}

		push @table, $row;
	}

    # Print banner
    print 'Memory' . "\n";
    print '------' . "\n\n";

	print_table(\@table);
	print "\n";
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

###############################################################################

sub print_table
{
    my ($tblRef) = @_;
	my @table = @$tblRef;

	# Determine column sizes #/
    my @headerWords = split(/\|/, $table[0]);
	my @colSize;
    foreach my $w (@headerWords)
    {
    	push @colSize, length $w;		
	}
    foreach my $r (@table)
    {
	    my @rowWords = split(/\|/, $r);

		for my $i (0 .. $#rowWords)
	    {
			$colSize[$i] = max($colSize[$i], length $rowWords[$i]); 	
		}
	}

	# Print header
	print '|';
	for my $i (0 .. $#headerWords)
    {
	    printf(" %*s |", -$colSize[$i], $headerWords[$i])
	}
	print "\n";

	# Print divider
	print '|';
	for my $i (0 .. $#headerWords)
    {
	    printf("%s|", '-' x ($colSize[$i] + 2))
	}
	print "\n";

	# Print rows
	for my $r (1 .. $#table)
    {
	    my @rowWords = split(/\|/, $table[$r]);

		print '|';
		for my $i (0 .. $#rowWords)
	    {
		    printf(" %*s |", -$colSize[$i], $rowWords[$i])
		}
		print "\n";
	}

#	print Dumper(@table);
}

