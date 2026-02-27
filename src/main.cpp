#include <move_obj_class/player.h>
#include <extra_class/map.h>
#include <extra_class/stats.h>

constexpr int PLAYER_CH = 'P';
constexpr int PLAYER_PAIR = 1;
constexpr int WALL_CH = '#';
constexpr int WALL_PAIR = 2;
constexpr int STATS_PAIR = 3;

int main() {
    SCREEN *s;
    s = newterm(NULL, stdout, stdin);
    set_term(s);

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
    init_pair(WALL_PAIR, COLOR_RED, COLOR_BLACK);
    init_pair(STATS_PAIR, COLOR_BLACK, COLOR_WHITE);

    int key;
    // Stats stats(3, 15, STATS_PAIR);
    Player player(PLAYER_CH, 1, PLAYER_PAIR);
    Map map(100, 100, WALL_CH, WALL_PAIR);
    map.set_cell(WALL, 10, 10);

    while (TRUE) {
        key = getch();
        if (key == KEY_CTRLC) break;

        // stats.draw(key, player.get_pos());
        map.draw(100, 100);
        player.update(key, map.get_maparr());
        
        refresh();
        // wnoutrefresh(stdscr);
        napms(30);
    }

    endwin();
    delscreen(s);
    return 0;
}