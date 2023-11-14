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

# Configure targets
IMG = sm
TARGET = $(IMG)

# Configure toolchain
cc = gcc
CC = $(cc)
LD = $(cc)
OBJCOPY = objcopy
SIZE = size
FLAGS += -DSIMU -DSMT_LOOPBACK
GCOV ?= 0

# Check gcc version
GCCVERSIONGTEQ5 := $(shell expr `gcc -dumpversion | cut -f1 -d.` \>= 5)

# Configure warnings
WARNS = -Wall -Wextra -Wno-missing-braces -Wno-missing-field-initializers \
    -Wfloat-equal -Wswitch-default -Wcast-align \
    -Wpointer-arith -Wredundant-decls -Wbad-function-cast -Wstrict-prototypes \
    -Wundef -Wcast-qual -Wshadow \
    -Wold-style-definition -Wno-unused-parameter -Werror \
    -Wformat=2 -Wnested-externs

FLAGS += ${WARNS}

#### SUMMARY OF COMPILER FLAGS ####
#
# DEPENDENCY GENERATION
# -MMD = generate dependency files for non-system headers
#
# OPTIMIZATION
# -Og = optimzation for debug
#
# DEBUG
# -g = enable debug info generation
#
# C LANGUAGE
# -std=gnu99 = support GNU C99
#
# CODE GENERATION
# -m32 = compile in 32-bit mode
# -fshort-enums = allocate enum as smallest type that can hold declared range
#
# OUTPUT
# -pipe = use pipes instead of temporary files
#
# SANITIZER OPTIONS
# -fsanitize=address = enable address sanitizer
# -fno-omit-frame-pointer = keep frame pointer in a register
# -fsanitize=undefined = enable undefined behavior sanitizer
#
###################################
CFLAGS = $(FLAGS) -MMD -std=gnu99 -m32 -fshort-enums -pipe
ifeq ($(GCOV),0)
CFLAGS += -Og -g
ifeq "$(GCCVERSIONGTEQ5)" "1"
CFLAGS += -fsanitize=address -fno-omit-frame-pointer -fsanitize=undefined
endif
else
CFLAGS += -O0 -DGCOV -fprofile-arcs -ftest-coverage
endif

#### SUMMARY OF LINKER FLAGS ####
#
# -m32 = link for 32-bit mode
# -Wl,-lrt = link RT library
#
# SANITIZER OPTIONS
# -lasan = link address sanitizer library
# -lubsan = link undefined behavior sanitizer library
#
#################################
ifeq ($(GCOV),0)
ifeq "$(GCCVERSIONGTEQ5)" "1"
LFLAGS = -lasan -lubsan
endif
endif
LFLAGS += -m32 -Wl,-lrt
ifeq ($(GCOV),1)
	LFLAGS += -lgcov --coverage
endif

