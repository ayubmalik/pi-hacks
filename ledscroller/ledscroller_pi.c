#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <wiringPi.h>

#include "ledscroller_pi.h"

const int leds[]  = {22, 27, 17, 24};

const int segments[] = {11,4,23,8,7,10,18,25};
const int dp[] = {0,0,0,0,0,0,0,1};

const int char_map[][NUM_SEGMENTS] = {
   {0,0,0,0,0,0,0,0},  // blank
   {1,1,1,1,1,1,0,0},  // 0
   {0,1,1,0,0,0,0,0},  // 1
   {1,1,0,1,1,0,1,0},  // 2
   {1,1,1,1,0,0,1,0},  // 3
   {0,1,1,0,0,1,1,0},  // 4
   {1,0,1,1,0,1,1,0},  // 5
   {1,0,1,1,1,1,1,0},  // 6
   {1,1,1,0,0,0,0,0},  // 7
   {1,1,1,1,1,1,1,0},  // 8
   {1,1,1,1,0,1,1,0},  // 9
   {1,1,1,1,1,1,1,0},  // Symbols
   {1,1,1,1,1,1,1,0},
   {1,1,1,1,1,1,1,0},
   {1,1,1,1,1,1,1,0},
   {1,1,1,1,1,1,1,0},
   {1,1,1,1,1,1,1,0},
   {1,1,1,1,1,1,1,0},
   {1,1,1,0,1,1,1,0},  // A
   {0,0,1,1,1,1,1,0},  // B
   {1,0,0,1,1,1,0,0},  // C
   {0,1,1,1,1,0,1,0},  // D
   {1,0,0,1,1,1,1,0},  // E
   {1,0,0,0,1,1,1,0},  // F
   {1,1,1,1,0,1,1,0},  // G
   {0,1,1,0,1,1,1,0},  // H
   {0,1,1,0,0,0,0,0},  // I
   {0,1,1,1,0,0,0,0},  // J
   {0,1,1,0,1,1,1,0},  // K
   {0,0,0,1,1,1,0,0},  // L
   {0,0,1,0,1,0,1,0},  // M
   {1,1,1,0,1,1,0,0},  // N
   {1,1,1,1,1,1,0,0},  // O
   {1,1,0,0,1,1,1,0},  // P
   {1,1,1,0,0,1,1,0},  // Q
   {1,0,0,0,1,1,0,0},  // R
   {1,0,1,1,0,1,1,0},  // S
   {0,0,0,1,1,1,1,0},  // T
   {0,1,1,1,1,1,0,0},  // U
   {0,1,1,1,1,1,0,0},  // V
   {0,1,1,1,1,1,0,0},  // W
   {0,1,1,0,1,1,1,0},  // X
   {0,1,1,1,0,1,1,0},  // Y
   {1,1,0,1,1,0,1,0},  // Z
};

void pi_all_leds_off() {
  for(int i=0; i < sizeof leds / sizeof *leds; i++) {
    pinMode(leds[i], OUTPUT);
    digitalWrite(leds[i], HIGH);
  }
}

int pi_init() {
  printf("Initialising Pi\n");
  wiringPiSetupGpio();
  pi_all_leds_off();
  for(int j=0; j < sizeof segments / sizeof *segments; j++) {
    pinMode(segments[j], OUTPUT);
    digitalWrite(segments[j], LOW);
  }

  return 0;
}

int pi_reset() {
  printf("Resetting Pi\n");
  for(int i=0; i < sizeof leds / sizeof *leds; i++) {
    pinMode(leds[i], INPUT);
    digitalWrite(leds[i], LOW);
  }

  for(int j=0; j < sizeof segments / sizeof *segments; j++) {
    pinMode(segments[j], INPUT);
    digitalWrite(segments[j], LOW);
  }
  return 0;
}

void pi_write_char(int pos, char c) {
  const int *bits;
  char C = toupper(c);
  if (C == '.') {
    bits = dp;
  } else if (C < '0' || C > 'Z') {
    bits = *char_map;
  } else {
    bits = char_map[1 + (C - '0')];
  }
  pi_all_leds_off();
  digitalWrite(leds[pos], LOW);
  for(int i=0; i < NUM_SEGMENTS; i++) {
    digitalWrite(segments[i], bits[i]);
  }
}
