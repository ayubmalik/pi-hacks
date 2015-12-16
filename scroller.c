#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wiringPi.h>

#define SCREEN_SIZE 4

int
main(int argc, char *argv[]) {
  printf("Scroller starting...\n");
  wiringPiSetupGpio() ;

  int digits[] = {22, 27, 17, 24};
  int pins[] = {7, 8, 25, 23, 18, 4, 10, 11};
  char *leds = malloc(SCREEN_SIZE);

  for(int i=0; i < sizeof digits / sizeof *digits; i++) {
    pinMode(digits[i], OUTPUT);
    digitalWrite(digits[i], LOW);
  }

  for(int j=0; j < sizeof pins / sizeof *pins; j++) {
    pinMode(pins[j], OUTPUT);
    digitalWrite(pins[j], HIGH);
    usleep(1000 * 100);
    digitalWrite(pins[j], LOW);
  }
  
  
  for(int k=0; k < SCREEN_SIZE; k++) {
    leds[k]='x';
  }
  
  printf("LEDS: %s\n", leds);
  sleep(1);
  return 0;
}

