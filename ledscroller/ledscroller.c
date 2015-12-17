#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "ledscroller_screen.h"

void check_usage(int argc) {
  if (argc != 3) {
    printf("\nusage: ledscroller <msg> <delay_in_ms>\n");
    exit(1);
  }
}

int main(int argc, char *argv[]) {
  check_usage(argc);
  char *message = argv[1];
  int scroll_delay_in_ms = strtol(argv[2], NULL, 10);
  scroll(message, scroll_delay_in_ms);
}
