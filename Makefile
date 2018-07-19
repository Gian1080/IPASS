#############################################################################
#
# Project Makefile
#
# (c) Wouter van Ooijen (www.voti.nl) 2016
#
# This file is in the public domain.
# 
#############################################################################

# source files in this project (main.cpp is automatically assumed)
SOURCES := MAX7219.cpp teeth.cpp Characters.cpp

# header files in this project
HEADERS := bitmap.hpp AbstractMAX7219.hpp MAX7219.hpp teeth.hpp Characters.hpp 

# other places to look for files for this project
SEARCH  := 

# set RELATIVE to the next higher directory 
# and defer to the Makefile.* there
RELATIVE := ..
include $(RELATIVE)/makefile.due
