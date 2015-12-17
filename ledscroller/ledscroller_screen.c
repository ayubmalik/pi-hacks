#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ledscroller_pi.h"

#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))
#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))

#define TEMP_SIZE 4

char* init_screen() {
  char *screen = malloc(sizeof(char) * TEMP_SIZE);
  for (int i = 0; i < TEMP_SIZE; i++) {
    screen[i] = ' ';
  }
  return screen;
}

void update_screen(char *screen, int screen_size, char *msg, int current_pos) {
  
  int offset = MIN(screen_size, current_pos);
  char *sub = malloc(sizeof(char) * screen_size);
  char *temp = malloc(sizeof(char) * screen_size);
  strncpy(sub, msg, 1 + offset);
  sprintf(temp, "%4s", sub);
  //strncpy(temp, msg, 1 + offset);
  printf("%s", temp);
  //strncpy(screen, msg + current_pos, offset);
}

void write_screen(char *screen) {
  printf("%s\n", screen);
}
