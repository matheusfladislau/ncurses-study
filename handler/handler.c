#include <ncurses.h>
#include "handler.h"

int HANDLE_WINCH = 0;

void handle_winch(int sig) {
    HANDLE_WINCH = 1;
}

void refresh_winsz_buffer() {
    HANDLE_WINCH = 0;
    endwin();
    refresh();
    clear();
}
