#include <ncurses.h>

#include "color.h"

void init_highlight_pair() {
    init_pair(HIGHLIGHT_PAIR, HIGHLIGHT_FOREGROUND, HIGHLIGHT_BACKGROUND);
}

void attr_highlight_color() {
    attron(COLOR_PAIR(HIGHLIGHT_PAIR));
}

void attroff_highlight_color() {
    attroff(COLOR_PAIR(HIGHLIGHT_PAIR));
}

void color() {
    start_color();
    init_highlight_pair();
    attr_highlight_color();
}
