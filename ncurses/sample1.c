#include "dbg.h"
#include <stdio.h>
#include <stdlib.h>
#include <curses.h>

int main(int argc, char *argv[]) {
  WINDOW * mainwin;
  
  debug("init main window");
  check(mainwin = initscr(), "Could not initscr");

  mvaddstr(13, 33, "Hello, world!");
  refresh();
  getch();

  delwin(mainwin);
  endwin();
  return EXIT_SUCCESS;

error:
  return EXIT_FAILURE;
}

