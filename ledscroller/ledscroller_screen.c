#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "ledscroller_pi.h"
#include "ledscroller_screen.h"

char* init_screen() {
  led_screen_t screen = malloc(sizeof(char) * NUM_LEDS);
  for (int i = 0; i < NUM_LEDS; i++) {
    screen[i] = ' ';
  }
  return screen;
}

void update_screen(led_screen_t screen, int screen_size, char *msg, int current_pos) {
  char *padding = malloc(screen_size -1);
  memset (padding, ' ', screen_size - 1);

  char *padded_msg = malloc(screen_size + strlen(msg) + 1);
  strcpy(padded_msg, padding);
  strcat(padded_msg, msg);
  strncpy(screen, padded_msg + current_pos, screen_size);
}

void write_screen(led_screen_t screen) {
  printf("%s\n", screen);
}

void scroll(char *msg, int delay_in_ms) {
  led_screen_t screen = init_screen();
  int pos = 0;
  for(;;) {
    update_screen(screen, strlen(screen), msg, pos++ % strlen(msg));
    write_screen(screen);
    sleepms(delay_in_ms);
  }
}

void sleepms(int millis) {
  usleep(1000 * millis);
}

