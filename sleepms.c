#include <stdio.h>

int main (int argc, char *argv[])
{
  if (argc > 1) 
  {
    int delay = strtol(argv[1], NULL, 10);
    usleep(1000 * delay);
  }
  return 0;
}

