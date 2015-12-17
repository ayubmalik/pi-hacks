CC=gcc
CFLAGS=-Wall -std=gnu99 -I.
DEPS=ledscroller_func.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) 

compile: ledscroller_pi.o ledscroller_screen.o

ledscroller: ledscroller_screen.o
	gcc -o $@ $^ $(CFLAGS)
	
clean:
	rm *.o
