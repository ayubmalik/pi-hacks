CC=gcc
CFLAGS=-Wall -std=gnu99 -I.
DEPS=ledscroller_pi.h ledscroller_screen.h ledscroller.h
OBJ=ledscroller_pi.o ledscroller_screen.o ledscroller.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

ledscroller: $(OBJ)
	gcc -o ledscroller ledscroller.o ledscroller_screen.o -I.

clean:
	rm *.o
	rm ledscroller
