all: hash.o myht.c
	gcc hash.o myht.c -o myht -lm -Wall

hash.o: hash.c hash.h
	gcc -c hash.c -Wall

clean:
	rm -f *.o

purge: clean
	rm -f myht
