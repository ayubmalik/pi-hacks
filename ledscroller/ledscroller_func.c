#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wiringPi.h>

#include "ledscroller_func.h"

int
init_scroller() {
  printf("Initialising Pi and data\n");
  wiringPiSetupGpio() ;

  for(int i=0; i < sizeof digits / sizeof *digits; i++) {
    pinMode(digits[i], OUTPUT);
    digitalWrite(digits[i], HIGH);
  }

  for(int j=0; j < sizeof segments / sizeof *segments; j++) {
    pinMode(segments[j], OUTPUT);
    digitalWrite(segments[j], LOW);
  }
  
  for(int k=0; k < SCREEN_SIZE; k++) {
    display[k]=' ';
  }
  
  return 0;
}


int
reset_pi() {
  printf("Resetting Pi");
  for(int i=0; i < sizeof digits / sizeof *digits; i++) {
    pinMode(digits[i], INPUT);
    digitalWrite(digits[i], LOW);
  }

  for(int j=0; j < sizeof segments / sizeof *segments; j++) {
    pinMode(segments[j], INPUT);
    digitalWrite(segments[j], LOW);
  }

  return 0;
}
