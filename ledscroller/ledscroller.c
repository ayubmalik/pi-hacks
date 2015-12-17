#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "ledscroller_screen.h"

int main(int argc, char *argv[])
{
  char *msg = "Hello World AbCdEf!";
  char *screen = init_screen(SCREEN_SIZE);
  for (int current_pos = 0; current_pos < 20; current_pos++) {
    update_screen(screen, sizeof(screen), msg, current_pos % strlen(msg));
  	write_screen(screen);
    sleep(1);
 }
}
