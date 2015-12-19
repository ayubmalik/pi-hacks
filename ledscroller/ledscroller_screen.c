#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "ledscroller_pi.h"
#include "ledscroller_screen.h"

char* screen_init() {
  screen_t screen = malloc(sizeof(char) * NUM_LEDS);
  for (int i = 0; i < NUM_LEDS; i++) {
    screen[i] = ' ';
  }
  return screen;
}

void screen_update(screen_t screen, int screen_size, char *msg, int current_pos) {
  int msg_len = strlen(msg);
  int offset = (current_pos % msg_len);
  char *padded_screen = malloc(screen_size);
  printf("%d\n", screen_size);
  memset(padded_screen, 'E', 4);
  //strncpy(padded_screen, msg + offset, screen_size);

  /*int pad_len = screen_size -  strlen(padded_screen);
  if (pad_len > 0) {
     char *padding = malloc(pad_len + 1);
     memset (padding, ' ', pad_len);
     strcat(padded_screen, padding);
  } */
  printf("pb %d %d |%s|\n", offset, strlen(padded_screen), padded_screen);
  strcpy(screen, padded_screen);
}

void screen_write(screen_t screen, int delay_in_ms) {
  printf("|%s|\n", screen);
  int hz = 4;
  int count = 0;
  
  while (count < delay_in_ms) {
    pi_write_char(0, screen[0]);
    sleepms(hz);
    pi_write_char(1, screen[1]);
    sleepms(hz);
    pi_write_char(2, screen[2]);
    sleepms(hz);
    pi_write_char(3, screen[3]);
    sleepms(hz);
    count += hz * 4;
 }
}

void screen_scroll(char *msg, int delay_in_ms) {
  pi_init();
  screen_t screen = screen_init();
  int screen_size = strlen(screen);
  char *padding = malloc(screen_size + 1);
  memset(padding, ' ', screen_size);
  char *padded_msg = malloc(strlen(msg) + screen_size + 1);
  strcpy(padded_msg, padding);
  strcat(padded_msg, msg);
  int pos = 0;
  for(;;) {
    screen_update(screen, strlen(screen), padded_msg, pos);
    screen_write(screen, delay_in_ms);
    pos++;
  }
}

void sleepms(int millis) {
  usleep(1000 * millis);
}

