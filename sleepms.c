#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char *argv[])
{
  if (argc > 1) 
  {
    long delay = strtol(argv[1], NULL, 10);
    usleep(1000 * delay);
  }
  return 0;
}

