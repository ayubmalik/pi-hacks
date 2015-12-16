#include <stdio.h>
#include <stdlib.h>
#include <wiringP.h>

#define SCREEN_SIZE 4

int
main(int argc, char *argv[]) {
  printf("Scroller starting...\n");

  char *leds = malloc(SCREEN_SIZE);

  for(int i=0; i < SCREEN_SIZE; i++) {
    leds[i]='x';
  }

  printf("LEDS: %s\n", leds);
  return 0;
}

