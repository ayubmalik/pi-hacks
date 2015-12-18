#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wiringPi.h>

#include "ledscroller_pi.h"

const int leds[]  = {22, 27, 17, 24};

const int segments[] = {11,4,23,8,7,10,18,25};

const int char_map[][NUM_SEGMENTS] = {
   {0,0,0,0,0,0,0},  // blank
   {1,1,1,1,1,1,0},  // 0
   {0,1,1,0,0,0,0},  // 1
   {1,1,0,1,1,0,1},  // 2
   {1,1,1,1,0,0,1},  // 3
   {0,1,1,0,0,1,1},  // 4
   {1,0,1,1,0,1,1},  // 5
   {1,0,1,1,1,1,1},  // 6
   {1,1,1,0,0,0,0},  // 7
   {1,1,1,1,1,1,1},  // 8
   {1,1,1,1,0,1,1},  // 9
   {1,1,1,1,1,1,1},  // Symbols
   {1,1,1,1,1,1,1},
   {1,1,1,1,1,1,1},
   {1,1,1,1,1,1,1},
   {1,1,1,1,1,1,1},
   {1,1,1,1,1,1,1},
   {1,1,1,1,1,1,1},
   {1,1,1,0,1,1,1},  // A
   {0,0,1,1,1,1,1},  // B
   {1,0,0,1,1,1,0},  // C
   {0,1,1,1,1,0,1},  // D
   {1,0,0,1,1,1,1},  // E
   {1,0,0,0,1,1,1},  // F
   {1,1,1,1,0,1,1},  // G
   {0,1,1,0,1,1,1},  // H
   {0,1,1,0,0,0,0},  // I
   {0,1,1,1,0,0,0},  // J
   {0,1,1,0,1,1,1},  // K
   {0,0,0,1,1,1,0},  // L
   {0,0,1,0,1,0,1},  // M
   {0,0,1,0,1,0,1},  // N
   {1,1,1,1,1,1,0},  // O
   {1,1,0,0,1,1,1},  // P
   {1,1,1,0,0,1,1},  // Q
   {1,0,0,0,1,1,0},  // R
   {1,0,1,1,0,1,1},  // S
   {0,0,0,1,1,1,1},  // T
   {0,1,1,1,1,1,0},  // U
   {0,1,1,1,1,1,0},  // V
   {0,1,1,1,1,1,0},  // W
   {0,1,1,0,1,1,1},  // X
   {0,1,1,1,0,1,1},  // Y
   {1,1,0,1,1,0,1},  // Z
};

int pi_init() {
  printf("Initialising Pi\n");
  wiringPiSetupGpio();

  for(int i=0; i < sizeof leds / sizeof *leds; i++) {
    pinMode(leds[i], OUTPUT);
    digitalWrite(leds[i], HIGH);
  }

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
  if (c < '0' || c > 'Z') {
    bits = *char_map;
  } else {
    bits = char_map[1+c - '0'];
  }
  
  digitalWrite(leds[pos], LOW);
  for(int i=0; i < NUM_SEGMENTS; i++) {
    digitalWrite(segments[i], bits[i]);
  }
}
