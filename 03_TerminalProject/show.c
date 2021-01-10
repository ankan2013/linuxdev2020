#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>

#define DX 3
#define ESCAPE 27
#define SPACE 32


void print_page(WINDOW *win, FILE *f, int width, int height) {
    char buf[width];
    for (int i = 0; i < height-1; i++) {
        memset(buf, 0, width);
        fgets(buf, width, f);
        wprintw(win, "%s", buf);
        if (feof(f)) {
            break;
        }
    }
    wrefresh(win);
}

int main(int argc, const char *argv[]) {
    
    if (argc != 2) {
        printf("The program expects a filename as the only argument\n");
	return 10;
    }

    FILE *f = fopen(argv[1], "r");
    if (f == NULL) {
        printf("A problem with file opening occured '%s'\n", argv[1]);
        return 11;
    }

    initscr();
    noecho();
    cbreak();

    printw("Filename: %s", argv[1]);
    refresh();

    int height = LINES-2*DX;
    int width = COLS-2*DX;
    WINDOW *win = newwin(width, height, DX, DX);

    keypad(win, TRUE);
    scrollok(win, TRUE);

    print_page(win, f, width, height);

    int c = wgetch(win);
    while (c != ESCAPE) {
        if (c == SPACE) {
            if (feof(f)) {
		c = wgetch(win);
                continue;
            }
            werase(win);
            print_page(win, f, width, height);

        }
        c = wgetch(win);
    }

    endwin();

    fclose(f);

    return 0;
}

