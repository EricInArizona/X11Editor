#!/bin/bash


cd /home/Eric/X11Editor

# pwd

# chmod +x aprogram.sh


# The warning about -Wpadded means it's aligning a struct
# or object on a boundary, like an 8 byte boundary.  Which
# is normal and fine.

# Can't do -Wl,--stack in Linux.
# See SetStack.cpp for that.

# -ftrapv  Generate  code  to  catch integer overflow errors.
#  Signed integer overflow is undefined in C.

# --help  Shows options.

#-Wl,something
# Pass something to the linker.

# Big L is telling it to add that directory to a search path
# for library files.
# -L/someDirectory
# Little l is telling it to link to that library.
# -lX11

# -H, --trace-includes
# Show header includes and nesting depth

# clang predefined macros all start with two underscores
# except for these two:
# linux 1
# unix 1

# List all clang predefined macros:
# clang++ -x c /dev/null -dM -E > Build.log

clang++ *.cpp /home/Eric/LinuxApi/*.cpp /home/Eric/X11Api/*.cpp -o X11Editor -Weverything -Wno-padded -Wno-c++98-compat-pedantic -ftrapv -Ofast  -lX11 2> Build.log


