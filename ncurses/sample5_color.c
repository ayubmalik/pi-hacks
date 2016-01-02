#define _XOPEN_SOURCE_EXTENDED
#include <stdio.h>
#include <stdlib.h>
#include <ncursesw/ncurses.h>
#include <unistd.h>
#include <locale.h>
#include "dbg.h"

#define sleepms(N) usleep(N*1000)

WINDOW *create_win(int height, int width, int starty, int startx);
void destroy_win(WINDOW *local_win);

int main() {
  setlocale(LC_ALL,"");
  WINDOW *win;
  check(win = initscr(), "could not initscr())");
  curs_set(0);
  start_color();
  init_pair(1, COLOR_WHITE, COLOR_BLACK);
  init_pair(2, COLOR_RED, COLOR_BLACK);
  char msg[] = "Hola!";
  int y=4, x=4;
  for(int i=0; i < 32; i += 4) {
    WINDOW *nwin = create_win(3, strlen(msg) + 5, y+i % 32, x+i % 32);
    mvwaddstr(nwin, 1, 2, msg);
    wrefresh(nwin);
    sleepms(1000);
    destroy_win(nwin);
  }

  endwin();

error:
  return EXIT_SUCCESS;

}

WINDOW *create_win(int height, int width, int starty, int startx) {
  WINDOW *win;
  win = newwin(height, width, starty, startx);
  //wborder(local_win, LS, RS, TS, BS, TL, TR, BL, BR);
  wattron(win, COLOR_PAIR(2));
  box(win, 0, 0);
  wattroff(win,COLOR_PAIR);
  wrefresh(win); 
  return win;
}  

void destroy_win(WINDOW *win) { 
  wclear(win);
  wrefresh(win);
  delwin(win);
}

