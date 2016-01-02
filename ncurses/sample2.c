#include "dbg.h"
#include <stdio.h>
#include <stdlib.h>
#include <curses.h>

int main(int argc, char *argv[]) {
  WINDOW * mainwin;

  debug("init main window");
  check(mainwin = initscr(), "Could not initscr");
  debug("LINES: %d, COLS: %d", LINES, COLS);

  char msg[] = "Hello there from ncurses!";
  int y = LINES / 2;
  int x = (COLS - strlen(msg))/2;

  attron(A_UNDERLINE);
  mvaddstr(y, x, msg);

  attrset(A_NORMAL);
  mvaddstr(++y, x, msg);
 
  refresh();
  getch();

  delwin(mainwin);
  endwin();
  return EXIT_SUCCESS;

error:
  return EXIT_FAILURE;
}

