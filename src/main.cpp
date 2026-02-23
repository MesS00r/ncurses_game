#include <move_obj_class/player.h>
#include <extra_class/map.h>

constexpr int PLAYER_CH = 'P';
constexpr int PLAYER_PAIR = 1;

int main() {
    SCREEN *s;
    s = newterm(NULL, stdout, stdin);

    if (has_colors() == FALSE) {
        printf("No color.");

        endwin();
        delscreen(s);
        return 0;
    }

    raw();
    nodelay(stdscr, TRUE);
    noecho();
    curs_set(0);

    start_color();
    init_pair(PLAYER_PAIR, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_BLACK, COLOR_WHITE);
    init_pair(3, COLOR_RED, COLOR_BLACK);

    int key, copy_key = 0;
    Player player(PLAYER_CH, 1, PLAYER_PAIR);

    Map map(100, 100, '#', 3);
    map.set_cell(WALL, 10, 10);

    while (1) {
        key = getch();
        if (key == KEY_CTRLC) {
            endwin();
            delscreen(s);
            return 0;
        }
        else if (key != -1) copy_key = key;

        attron(COLOR_PAIR(2) | A_BOLD);
        mvprintw(0, 0, "x, y: %d, %d", player.get_pos().x, player.get_pos().y);
        mvprintw(1, 0, "key: %c:%d", copy_key, copy_key);
        attroff(COLOR_PAIR(2) | A_BOLD);

        map.draw(100, 100);
        player.update(key, map.get_maparr());

        refresh();
        napms(30);
        erase();
    }
    
    endwin();
    delscreen(s);
    return 0;
}
