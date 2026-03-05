#include <move_obj_class/player.h>
#include <extra_class/map.h>
#include <extra_class/stats.h>
#include <memory>

constexpr chtype_i PLAYER_CH = '@';
constexpr chtype_i WALL_CH = '#';

constexpr int PLAYER_PAIR = 1;
constexpr int WALL_PAIR = 2;
constexpr int STATS_PAIR = 3;

// const Tvec STATS_SIZE = {15, 3};
// const Tvec MAP_SIZE = {100, 50};

struct GameSession {
    std::unique_ptr<Stats> stats;
    std::unique_ptr<Player> player;
    std::unique_ptr<Map> map;

    GameSession() {
        raw();
        nodelay(stdscr, TRUE);
        noecho();
        curs_set(0);

        start_color();
        init_pair(STATS_PAIR, COLOR_BLACK, COLOR_WHITE);
        init_pair(PLAYER_PAIR, COLOR_GREEN, COLOR_BLACK);
        init_pair(WALL_PAIR, COLOR_RED, COLOR_BLACK);

        stats = std::make_unique<Stats>(Tvec{15, 3}, STATS_PAIR, Tvec{1, 2});
        player = std::make_unique<Player>(PLAYER_CH, 1, PLAYER_PAIR, Tvec{1, 2});
        map = std::make_unique<Map>(Tvec{100, 50}, WALL_CH, WALL_PAIR);

        map->set_cell(WALL, {10, 15});
    }
};

exit_code loop(GameSession& session) {
    chtype_i key = getch();
    if (key == KEY_CTRLC) return EXIT;

    session.stats->draw(key, session.player->get_pos());
    session.map->draw({100, 50});
    session.player->update(key, session.map->get_maparr());
    
    wnoutrefresh(stdscr); 
    napms(NAPMS);
    return CONTINUE;
}

int main() {
    SCREEN *s = newterm(NULL, stdout, stdin);
    set_term(s);

    if (has_colors() == FALSE) {
        printf("No color.");

        endwin();
        delscreen(s);
        return 0;
    }

    GameSession session;
    while (TRUE) {
        if (loop(session) == EXIT) break;
    }

    endwin();
    delscreen(s);
    return 0;
}