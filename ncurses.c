#include <ncurses.h>
#include <signal.h>
#include <string.h>

#include "handler/handler.h"
#include "color/color.h"

void delete_window(WINDOW* win) {
    if (win != NULL) {
        wclear(win);
        wrefresh(win);
        delwin(win);
    }
}

int center_text_msg(char *txt) {
    return getmaxx(stdscr) / 2 - strlen(txt) / 2;
}

WINDOW* menu(int cur_x, int cur_y) {
    WINDOW *win = newwin(cur_y - 5, cur_x, 2, 0);
    box(win, 0, 0);
    mvwprintw(win, 0, 4, "Menu");
    mvwprintw(win, 1, 1, "1. Escrever uma palavra;");
    mvwprintw(win, 2, 1, "2. Criar uma janela;");
    mvwprintw(win, 3, 1, "3. Sair");
    wrefresh(win);
    keypad(win, TRUE);

    return win;
}

int main() {
    initscr();
    noecho();
    keypad(stdscr, TRUE);
    signal(SIGWINCH, handle_winch);

    WINDOW *win = NULL;
    while (1) {
        if (HANDLE_WINCH == 0) { continue; }
        refresh_winsz_buffer();
        start_color();

        int x = getmaxx(stdscr);
        int y = getmaxy(stdscr);

        char msg[] = "ncurses\n";
        mvaddstr(1, center_text_msg(msg), msg); 

        char temp[4];
        sprintf(temp, "%dx%d", x, y);

        color();
        mvaddstr(y - 1, 1, temp);
        attroff_highlight_color();

        refresh();
        win = menu(x, y);
    }
    delete_window(win);
    endwin();
    return 0;
}
