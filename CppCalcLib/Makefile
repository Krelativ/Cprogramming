############################################################################
# 'A Generic Makefile for Building Multiple main() Targets in $PWD'
# Author:  Robert A. Nader (2012) 
# modified by kmuhamm1
############################################################################
BUILD_DIR = ./build/
SRC_DIR=./src/
CC= g++
CFLAGS_INC := -Iinc
CFLAGS := -g -Wall $(CFLAGS_INC)
LDFLAGS := -lm
##### for static library ######
ALIB=calc.a
AR=ar
ARFLAGS=rcs
##### for shared library ######
SLIB=calc.so
SL_LDFLAGS = -lm
#
## ==================- NOTHING TO CHANGE BELOW THIS LINE ===================
##
# wildcard gets every file in specified path (i.e: inside SRC_DIR)
# SRCS := $(wildcard $(SRC_DIR)*.c)
SRCS += $(wildcard $(SRC_DIR)*.cpp)
# for every file in SRCS, replace .c with .o to obtain object files
# PRGS := $(SRCS:.c=.o)
PRGS += $(SRCS:.cpp=.o)
# modify path of object files to be in the build directory
OBJS := $(subst $(SRC_DIR),$(BUILD_DIR),$(PRGS))
BINS := artifact
#test:
#	echo $(SRCS)
#	echo $(PRGS)
#	echo $(OBJS)
all: $(SLIB) $(ALIB) 
#$(BINS) 

## Compile the executables
$(BINS): $(OBJS) 
	$(CC) $(CFLAGS) $(LDFLAGS) $< -o $@

##### for static library ######
$(ALIB): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^
	
##### for shared library ######
$(SLIB): $(OBJS)
	$(CC) $(CFLAGS) -shared $^ -o $@ $(SL_LDFLAGS)

$(OBJS) : $(SRCS)
	mkdir build
	$(CC) $(CFLAGS) -MMD -c $< -o $@

make_dir:
	mkdir build

clean:
	del /f $(BINS).exe 
	del /f $(SLIB) 
	# del /f $(ALIB)
	rmdir /s /q build

rebuild: clean all
