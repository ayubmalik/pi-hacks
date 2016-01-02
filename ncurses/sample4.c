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
  char msg[] = "Hi ";
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
  WINDOW *local_win;
  local_win = newwin(height, width, starty, startx);
  //wborder(local_win, LS, RS, TS, BS, TL, TR, BL, BR);
  box(local_win, 0 , 0);    
  wrefresh(local_win); 
  return local_win;
}  

void destroy_win(WINDOW *local_win) { 
  wclear(local_win);
  wrefresh(local_win);
  delwin(local_win);
}

