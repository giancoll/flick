#
# Copyright (c) 1999 The University of Utah and
# the Computer Systems Laboratory at the University of Utah (CSL).
#
# This file is part of Flick, the Flexible IDL Compiler Kit.
#
# Flick is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#
# Flick is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with Flick; see the file COPYING.  If not, write to
# the Free Software Foundation, 59 Temple Place #330, Boston, MA 02111, USA.
#

###############################################################################

## FLICK CONFIGURATION.

# Set this to your Flick source tree.
SRCDIR		= /home/users/barneyrubble/flick-src
# Set this to your Flick object directory.
OBJDIR		= /home/users/barneyrubble/flick-obj

# The Flick stubs need header files from the Flick source and object trees, if
# Flick hasn't already been installed.
CPPFLAGS	= -I$(OBJDIR)/runtime/headers \
		  -I$(SRCDIR)/runtime/headers
# ACE include dir added by `wrapper_macros'; see below.
# TAO include dir added by `taoconfig.mk'; see below.
#		  -I$(ACE_ROOT)
#		  -I$(TAO_ROOT)

###############################################################################

## MACROS THAT DESCRIBE WHAT WE ARE BUILDING.

IDL_FILES	= phone.idl

CLIENT		= phonebook
CLIENT_OBJS	= client.o phoneC.o phoneS.o

SERVER		= phoneserver
SERVER_OBJS	= server.o phoneC.o phoneS.o phone_i.o

# The set of files generated by Flick.  Removed by `make clean'.
FLICK_GEN_FILES	= $(strip \
			$(foreach file,$(IDL_FILES),\
				$(addprefix $(basename $(file)),\
					.aoi .aod \
					C.prc C.prd S.prc S.prd \
					C.cc C.h S.cc S.h)))

###############################################################################

## ACE/TAO CONFIGURATION.
##
## We include some of the ACE/TAO Makefiles so that we know how to properly
## compile our generated code for TAO (i.e., what C++ compiler, what options).

ifndef ACE_ROOT
  # GNU Make 3.78 provides $(error ...), but the following works, too.
  error :=$(shell echo >&2 You must define the ACE_ROOT environment variable.)
  error
endif
ifndef TAO_ROOT
  TAO_ROOT = $(ACE_ROOT)/TAO
endif

BIN	= $(CLIENT) $(SERVER)
BUILD	= $(BIN)
LDLIBS	= -lTAO

include $(ACE_ROOT)/include/makeinclude/wrapper_macros.GNU
# Files includes by TAO examples, but which we don't need:
# include $(ACE_ROOT)/include/makeinclude/macros.GNU
# include $(TAO_ROOT)/rules.tao.GNU
# include $(ACE_ROOT)/include/makeinclude/rules.common.GNU
# include $(ACE_ROOT)/include/makeinclude/rules.nonested.GNU
# include $(ACE_ROOT)/include/makeinclude/rules.bin.GNU
# include $(ACE_ROOT)/include/makeinclude/rules.local.GNU
include $(TAO_ROOT)/taoconfig.mk

###############################################################################

## HOW TO BUILD C++ STUBS AND SKELETONS FOR TAO USING FLICK.

# The Flick programs.
FLICK_FE_CORBA		= $(OBJDIR)/bin/flick-fe-newcorba
FLICK_PG_CORBAXX	= $(OBJDIR)/bin/flick-c-pfe-corbaxx
FLICK_BE_IIOPXX		= $(OBJDIR)/bin/flick-c-pbe-iiopxx

# The Flick front end options.
FLICK_FE_FLAGS		=

# The Flick presentation generator options.
FLICK_PG_FLAGS		=
FLICK_PG_CLIENT_FLAGS	= $(FLICK_PG_FLAGS) -c
FLICK_PG_SERVER_FLAGS	= $(FLICK_PG_FLAGS) -s

# The Flick back end options.  These options are a little complicated when
# Flick generates code for TAO.  Basically:
#
#  + We tell the back end where to find the templates that Flick needs in order
#    to generate code for TAO (`--nostdinc -I ...').
#  + We cause the generated client `.cc' file to `#include' the server-side
#    `.h' file (`-f ...').
#  + We cause the generated server `.cc' file to `#include' the client-side
#    `.h' file (-F ...').
#
FLICK_BE_FLAGS		= --nostdinc -I $(SRCDIR)/runtime/headers/flick/pres
FLICK_BE_CLIENT_FLAGS	= $(FLICK_BE_FLAGS) \
			  -f $(addsuffix .h,\
				$(patsubst %C,%S,$(basename $@)))
FLICK_BE_SERVER_FLAGS	= $(FLICK_BE_FLAGS) \
			  -F $(addsuffix .h,\
				$(patsubst %S,%C,$(basename $@)))

##

%.aoi: %.idl
	$(FLICK_FE_CORBA) $(FLICK_FE_FLAGS) -o $@ $<

%C.prc: %.aoi
	$(FLICK_PG_CORBAXX) $(FLICK_PG_CLIENT_FLAGS) -o $@ $<

%S.prc: %.aoi
	$(FLICK_PG_CORBAXX) $(FLICK_PG_SERVER_FLAGS) -o $@ $<

%C.cc %C.h: %C.prc
	$(FLICK_BE_IIOPXX) $(FLICK_BE_CLIENT_FLAGS) -h $*C.h -o $*C.cc $<

%S.cc %S.h: %S.prc
	$(FLICK_BE_IIOPXX) $(FLICK_BE_SERVER_FLAGS) -h $*S.h -o $*S.cc $<

.PRECIOUS: %.aoi %C.prc %S.prc %C.cc %C.h %S.cc %S.h

###############################################################################

## HERE ARE THE GENERIC TOP-LEVEL TARGETS (`all', `clean', ...).

.PHONY: all
all:	$(CLIENT) $(SERVER)

.PHONY: clean
clean:
	$(RM) $(FLICK_GEN_FILES) \
	      $(sort $(CLIENT_OBJS) $(SERVER_OBJS)) \
	      $(CLIENT) $(SERVER)

## HERE ARE THE SPECIFIC TOP-LEVEL TARGETS.

$(SERVER): $(SERVER_OBJS)
	$(LINK.cc) $(LDFLAGS) -o $@ $^ $(VLDLIBS) $(POSTLINK)

$(CLIENT): $(CLIENT_OBJS)
	$(LINK.cc) $(LDFLAGS) -o $@ $^ $(VLDLIBS) $(POSTLINK)

###############################################################################

## INDIVIDUAL FILE DEPENDENCIES.

phoneC.o: \
	phoneC.cc \
	phoneC.h \
	phoneS.h
phoneS.o: \
	phoneS.cc \
	phoneS.h \
	phoneC.h
server.o: \
	server.cc \
	phone_i.h \
	phoneS.h \
	phoneC.h
client.o: \
	client.cc \
	phoneC.h
phone_i.o: \
	phone_i.cc \
	phoneC.h \
	phoneS.h

###############################################################################

## End of file.

