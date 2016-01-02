CC=gcc -std=gnu99
CFLAGS=-Wall
LDFLAGS=-lncursesw -lpanel
INCLUDES=-I../includes
SAMPLES:=$(wildcard sample*.c)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all: $(patsubst %.c, %, $(SAMPLES))

sample%: sample%.o
	$(CC) -o $@ $< $(LDFLAGS)

.PHONY: clean
clean:
	find . -regex "\.\/sample[^\.]*" -print -delete
