CC=g++ #creates variable CC for gcc compiling
CFLAGS= -c -Wall #stores options to pass to the c compiler. -c is for compiling into an object and -wall is for compiler warnings

all: task1 task2 #running make builds the program, compiles the two files seperately

task1.o: task1.c #shows task1.o is dependent on task1.c and creates object
	$(CC) $(CFLAGS) task1.c -o task1
#compiles task1.c and checks for common compiler warnings

task2.o: task2.c #shows task2.o is dependent on task2.c and creates object
	$(CC) $(CFLAGS) task2.c -o task2
#compiles task2.c and checks for common compiler warnings

clean:
	rm -f *.o prog
#deletes object files and executable files, but leaves source code untouched.
