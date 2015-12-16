CC=gcc
CFLAGS=-Wall -std=gnu99 -I.
DEPS=ledscroller.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) 

compile: ledscroller.o

ledscroller: ledscroller.o
	echo "Cant build on ubuntu"

clean:
	rm ledscroller.o
