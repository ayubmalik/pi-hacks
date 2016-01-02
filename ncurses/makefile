CC=gcc
CFLAGS=-Wall
LDFLAGS=-lncurses
INCLUDES=-I/home/ayub/workspace/c/includes
DEPS=

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all: sample1 sample2

sample%: sample%.o
	$(CC) -o $@ $< $(LDFLAGS)

.PHONY: clean

clean:
	find . -regex "\.\/sample[0-9]+" -delete

