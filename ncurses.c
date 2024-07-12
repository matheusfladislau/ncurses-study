#include <curses.h> //-> already implements <stdio.h>
#include <string.h>

//WINDOW -> estrutura que descreve um sub-retângulo na tela
//it is more like a scratchpad or write buffer

//The routines can use several windows, 
//but two are automatically given: curscr, which knows what the 
//terminal looks like, and stdscr, which is what the programmer wants the 
//terminal to look like next. The user should never actually access 
//curscr directly. Changes should be made to through the API, and then the 
//routine refresh() (or wrefresh()) called.

void delete_window(WINDOW* win) {
    wclear(win);
    wrefresh(win);
    delwin(win);
}

int main() {
    initscr();
    noecho();
    keypad(stdscr, TRUE);

    char msg[] = "NCurses\n";
    int len = strlen(msg);
    mvaddstr(1, (getmaxx(stdscr)/2)-len, msg); //move and add str to x,y
    mvaddstr(getmaxy(stdscr)-2, 1, "Teste de NCurses - https://www.gnu.org/software/ncurses/ncurses-intro.html");

    refresh(); //make the portion of the terminal covered by window look like the code above
    //getch();

    WINDOW *win = newwin(getmaxy(stdscr)-5, getmaxx(stdscr), 2, 0); //create new window
    box(win, 0, 0);
    mvwprintw(win, 0, 4, "Menu");
    mvwprintw(win, 1, 1, "1. Escrever uma palavra;");
    mvwprintw(win, 2, 1, "2. Criar uma janela;");
    mvwprintw(win, 3, 1, "3. Sair.");
    wrefresh(win);
    keypad(win, TRUE);

    int i = 1;
    wmove(win, i, 1);
    while (1) {
        int c = wgetch(win);
        switch (c) {
            case KEY_UP:
                if ((i-1) >= 1) {
                    wmove(win, --i, 1);
                } else {
                    wmove(win, 1, 1);
                } 
                mvprintw(getmaxy(stdscr)-3, 1, "Tecla pressionada: cima.\n");
                break;
            case KEY_DOWN:
                if ((i+1) <= 3) {
                    wmove(win, ++i, 1);
                } else {
                    wmove(win, 3, 1);
                }
                mvprintw(getmaxy(stdscr)-3, 1, "Tecla pressionada: baixo.\n");
                break;
            case KEY_ENTER:
                mvprintw(getmaxy(stdscr)-3, 1, "Tecla pressionada: enter.\n");
                break;
            default:
                mvprintw(getmaxy(stdscr)-3, 1, "Aperte para cima, baixo ou enter!\n");
                wmove(win, i, 1);
                break;
        }       
        refresh();
    }

    //WINDOW *subwin = derwin(win, 5, 5, 2, 2);
    //box(subwin, 0, 0);
    //wrefresh(subwin);
    //getch();
    //delete_window(subwin);

    //getch();
    //delete_window(win);

    getch();
    endwin(); //always call before exiting or shelling out of the program
    return 0;
}


//touchwin(stdscr); //make refresh() check the whole terminal for changes, including other windows
//echo(); //make getch() print on screen

