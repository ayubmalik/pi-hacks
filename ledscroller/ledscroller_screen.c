#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ledscroller_pi.h"

char* init_screen(int size) {
  char *screen = malloc(sizeof(char) * size);
  for (int i = 0; i < size; i++) {
    screen[i] = ' ';
  }
  return screen;
}

void update_screen(char *screen, int screen_size, char *msg, int current_pos) {
  strncpy(screen, msg + current_pos, screen_size);
}

void write_screen(char *screen) {
  printf("%s\n", screen);
}
