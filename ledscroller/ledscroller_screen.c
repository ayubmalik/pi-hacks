#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "ledscroller_pi.h"
#include "ledscroller_screen.h"
#define PAD_CHAR ' '

char* screen_init() {
  screen_t screen = malloc(sizeof(char*) * (NUM_LEDS + 1));
  memset(screen, PAD_CHAR, NUM_LEDS);
  return screen;
}

void screen_update(screen_t screen, int screen_size, char *msg, int current_pos) {
  int msg_len = strlen(msg);
  int offset = (current_pos % msg_len);
  char *padded_screen = screen_init();
  
  strncpy(padded_screen, msg + offset, screen_size);
  int pad_len = screen_size -  strlen(padded_screen);
  //printf("%d %d %d\n", offset, screen_size, pad_len);
  if (pad_len > 0) {
     char *rpad = malloc(pad_len + 1);
     memset (rpad, PAD_CHAR, pad_len);
     strcat(padded_screen, rpad);
  }
  //printf("pb %d %d |%s|\n", offset, strlen(padded_screen), padded_screen);
  strncpy(screen, padded_screen, screen_size);
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

