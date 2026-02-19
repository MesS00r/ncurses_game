#include <cstdio>
#include <ncurses.h>
#include <move_obj_class/player.h>

#define KEY_CTRLC 3

#define PLAYER_CH 'P'
#define PLAYER_PAIR 2

int main() {
    SCREEN *s;
    s = newterm(NULL, stdout, stdin);

    raw();
    nodelay(stdscr, TRUE);
    noecho();
    curs_set(0);

    bool color;
    if ((color = has_colors()) == TRUE) {
        start_color();
        init_pair(1, COLOR_BLACK, COLOR_WHITE);
        init_pair(PLAYER_PAIR, COLOR_GREEN, COLOR_BLACK);   
    }

    int key, copy_key = 0;
    Player player(PLAYER_CH, 1, PLAYER_PAIR);

    while (1) {
        key = getch();
        if (key == KEY_CTRLC) {
            endwin();
            delscreen(s);
            return 0;
        }
        else if (key != -1) copy_key = key;

        attron((color ? COLOR_PAIR(1) : 0) | A_BOLD);

        mvprintw(0, 0, "x, y: %d, %d", player.get_pos().x, player.get_pos().y);
        mvprintw(1, 0, "key: %c:%d", copy_key, copy_key);
        if (color == FALSE) mvprintw(2, 0, "no color");

        attroff((color ? COLOR_PAIR(1) : 0) | A_BOLD);

        player.update(key);

        refresh();
        napms(30);
        erase();
    }
    
    endwin();
    delscreen(s);
    return 0;
}
