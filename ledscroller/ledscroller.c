#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

#include "ledscroller_screen.h"
#include "ledscroller_pi.h"

void check_usage(int argc) {
  if (argc != 3) {
    printf("\nusage: ledscroller <msg> <delay_in_ms>\n");
    exit(1);
  }
}

void intHandler(int sig) {
  pi_reset();
  exit(1);
}

int main(int argc, char *argv[]) {
  signal(SIGINT, intHandler);
  check_usage(argc);
  /*
  char *message = argv[1];
  int scroll_delay_in_ms = strtol(argv[2], NULL, 10);
  scroll(message, scroll_delay_in_ms);
  */  
  pi_init();
  
  char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ9876543210";
  for (int i = 0; i < strlen(charset); i++) {
    pi_write_char(0,charset[i]);
    pi_write_char(1,charset[i]);
    pi_write_char(2,charset[i]);
    pi_write_char(3,charset[i]);
    sleepms(500);
  }
  
  pi_reset();
}
