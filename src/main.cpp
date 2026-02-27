#include <move_obj_class/player.h>
#include <extra_class/map.h>
#include <extra_class/stats.h>

constexpr int PLAYER_CH = 'P';
constexpr int PLAYER_PAIR = 1;
constexpr int WALL_CH = '#';
constexpr int WALL_PAIR = 2;
constexpr int STATS_PAIR = 3;

int key;
Stats *stats;
Player *player;
Map *map;

void setup() {
    raw();
    nodelay(stdscr, TRUE);
    noecho();
    curs_set(0);

    start_color();
    init_pair(PLAYER_PAIR, COLOR_GREEN, COLOR_BLACK);
    init_pair(WALL_PAIR, COLOR_RED, COLOR_BLACK);
    init_pair(STATS_PAIR, COLOR_BLACK, COLOR_WHITE);

    stats = new Stats(3, 15, STATS_PAIR);
    player = new Player(PLAYER_CH, 1, PLAYER_PAIR);
    map = new Map(100, 100, WALL_CH, WALL_PAIR);
}

exit_code loop() {
    key = getch();
    if (key == KEY_CTRLC) return EXIT;

    stats->draw(key, player->get_pos());
    map->draw(100, 100);
    player->update(key, map->get_maparr());
    
    wnoutrefresh(stdscr); 
    napms(30);
    return CONTINUE;
}

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

    setup();
    while (TRUE) { if (loop() == EXIT) break; }

    delete stats;
    delete player;
    delete map;

    endwin();
    delscreen(s);
    return 0;
}