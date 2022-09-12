all: myProgram

myProgram: src/main.o libmymalloc.a #libmymalloc.a is the dependency for the executable
	gcc -lm -o myProgram src/main.o -L. -lmymalloc

main.o: src/main.c
	gcc -O -c src/main.c include/mymalloc.h

myMalloc.o: src/mymalloc.c include/mymalloc.h
	gcc -O -c src/mymalloc.c

libmymalloc.a: myMalloc.o #links library files into a static library
	ar rcs libmymalloc.a mymalloc.o

libs: libmymalloc.a

clean:
	rm -f myProgram *.o *.a *.gch #clean