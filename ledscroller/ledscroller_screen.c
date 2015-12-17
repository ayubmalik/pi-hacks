#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wiringPi.h>

#include "ledscroller_pi.h"

void
write_screen(char *screen) {
  printf("%s\n", screen);
}
