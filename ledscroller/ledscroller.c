#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "ledscroller_screen.h"

int
main(int argc, char *argv[])
{
	char screen[] = {'a'};
	write_screen(screen);
}
