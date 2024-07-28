#include <ncurses.h>

extern int HANDLE_WINCH;

void handle_winch(int sig);
void refresh_winsz_buffer();
