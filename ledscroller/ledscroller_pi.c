#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wiringPi.h>

#include "ledscroller_pi.h"

#define MS 1000
const int digits[]  = {22, 27, 17, 24};

const int segments[] = {11,4,23,8,7,10,18,25};

const int char_map[][NUM_SEGMENTS] = {
  {1, 1, 1, 1, 1, 1, 0},
  {0, 1, 1, 0, 0, 0, 0}
};

int pi_init() {
  printf("Initialising Pi and data\n");
  wiringPiSetupGpio();

  for(int i=0; i < sizeof digits / sizeof *digits; i++) {
    pinMode(digits[i], OUTPUT);
    digitalWrite(digits[i], HIGH);
  }

  for(int j=0; j < sizeof segments / sizeof *segments; j++) {
    pinMode(segments[j], OUTPUT);
    digitalWrite(segments[j], LOW);
  }

  return 0;
}


int pi_reset() {
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

void pi_write_char(char c) {
  if (c < '0' || c > 'Z') {
    printf("non printable char: %c\n", c);
    return;
  }
  
  digitalWrite(22, LOW);
  const int *bits = char_map[c - '0'];
  for(int i=0; i < NUM_SEGMENTS; i++) {
    digitalWrite(segments[i], bits[i]);
  }
}
