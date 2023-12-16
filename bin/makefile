# --------------------------------------------------
# Makefile for calling a Fortran function from C
# --------------------------------------------------

# Files Folder
src = ../src

# Exe name
exe = test-fortran-c.out

# Compiler
FC = gfortran
CC = gcc

# Flags
W_flags = -Wall -Wextra -Werror
Opt_flags = #-O3 -march=native -flto=8 -fno-fat-lto-objects -fno-strict-aliasing
COMM_flags = -g
FC_flags = -std=f2018 -ffree-line-length-none -fcheck=all
CC_flags = -I $(src)
LFLAGS = -lgfortran

# Concatenate flags and compiler into one command
FC_Mod = $(FC) -c $(COMM_flags) $(FC_flags) $(W_flags) $(Opt_flags)
CC_Mod = $(CC) -c $(COMM_flags) $(CC_flags) $(W_flags)
CC_Lin = $(CC) -g $(Opt_flags) 

#List of objects to compile
File_list = fortran_func.o main.o

#------------------------
# Build
all: $(File_list)
	$(CC_Lin) *.o -o $(exe) $(LFLAGS)


#------------------------
# Generic rules
%.mod: %.o
	@true

%.o: $(src)/%.f90
	$(FC_Mod) $<

%.o: $(src)/%.c
	$(CC_Mod) $<

# Objects list and dependencies
fortran_func.o: $(src)/fortran_func.f90
main.o: $(src)/main.c


#------------------------
# Clean make dir
clean:
	rm *.o *.mod $(exe)

#------------------------
# Run the code
run:
	./$(exe)

#------------------------
# Run valgrind to debug memory
# Flags
Val_flags = --leak-check=full --show-reachable=yes --track-origins=yes

mem-debug:
	valgrind $(Val_flags) ./$(exe)