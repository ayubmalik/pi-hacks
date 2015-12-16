CC=gcc
CFLAGS=-Wall -std=gnu99 -I.
DEPS=ledscroller_func.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) 

compile: ledscroller_func.o

ledscroller: ledscroller_func.o
	echo "Cant build on ubuntu"

clean:
	rm *.o
