## ###################################################################
##
## Copyright 2023 NXP
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

include ../makefiles/dox.mak

OUT = ./build

# Configure verbose logging
ifdef v
    V := $(v)
endif
ifeq ($(V),1)
    AT :=
else
    AT := @
endif
export AT

all: clean html rtf pdf

include ../makefiles/build_info.mak

.SUFFIXES :

html : rnotes.md html.cfg
	@echo "Generating html"
	$(AT)mkdir -p $(OUT)
	$(AT)$(DOXYGEN) html.cfg

rtf : rnotes.md rtf.cfg
	@echo "Generating rtf"
	$(AT)mkdir -p $(OUT)
	$(AT)$(DOXYGEN) rtf.cfg

latex : rnotes.md latex.cfg
	@echo "Generating latex"
	$(AT)mkdir -p $(OUT)
	$(AT)$(DOXYGEN) latex.cfg
	$(AT)sed -i -f refman.sed $(OUT)/latex/refman.tex

pdf : latex
	@echo "Generating pdf"
	$(AT)cd $(OUT)/latex && $(MAKE) >/dev/null 2>/dev/null
	$(AT)cp $(OUT)/latex/refman.pdf ./sm-rm.pdf

rn : rn.md
	@echo "Generating rn"
	$(AT)mkdir -p $(OUT)
	$(AT)$(DOXYGEN) rn.cfg
	$(AT)rm -f rn.md
	$(AT)sed -i -f refman.sed $(OUT)/latex/refman.tex
	$(AT)cd $(OUT)/latex && $(MAKE) >/dev/null 2>/dev/null
	$(AT)cp $(OUT)/latex/refman.pdf ./sm-rn.pdf

rnotes.md : rn.md
	@echo "Generating rnotes"
	$(AT)mkdir -p $(OUT)
	$(AT)cp rn.md rnotes.md
	$(AT)cat rn_cl.md >> rnotes.md
	$(AT)cat rn_kn.md >> rnotes.md
	$(AT)cat rn_add.md >> rnotes.md
	$(AT)sed -i -- 's/mainpage/RN_INTRO/g' rnotes.md
	$(AT)sed -i -- 's/Introduction/Release Notes/g' rnotes.md

rn.md : rn_info.sed
	@echo "Generating data"
	$(AT)mkdir -p $(OUT)
	$(AT)rm -f rn.md
	$(AT)cp rn_intro.md rn.md
	$(AT)chmod 777 rn_info.sed
	$(AT)./rn_info.sed
	$(AT)rm -f rn_info.sed

clean:
	@echo "Cleaning ...."
	$(AT)rm -rf $(OUT)
	$(AT)rm -f dox_log.txt
	$(AT)rm -f rn.md
	$(AT)rm -f rnotes.md
	$(AT)rm -f sm-rm.pdf
	$(AT)rm -f sm-rn.pdf

