#include <ncurses.h>

#define HIGHLIGHT_PAIR 1
#define HIGHLIGHT_FOREGROUND COLOR_BLACK
#define HIGHLIGHT_BACKGROUND COLOR_RED

void init_highlight_pair();

void attr_highlight_color();

void attroff_highlight_color();

void color();
