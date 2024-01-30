.PHONY: all clean test

all: ni ekki
	gcc -o ekki ekki.o
	gcc -o ni ni.o

ekki: ekki.c
	gcc -c -o ekki.o ekki.c

ni.o: ni.c 
	gcc -c -o ni.o ni.c

test: all
	./ekki

clean: 
	rm -rf *.o ni ekki
	
