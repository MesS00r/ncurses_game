#include <move_obj_class/player.h>
#include <extra_class/map.h>
#include <extra_class/stats.h>
#include <memory>

constexpr chtype_i PLAYER_CH = '@';
constexpr chtype_i WALL_CH = '#';

constexpr int PLAYER_PAIR = 1;
constexpr int WALL_PAIR = 2;
constexpr int STATS_PAIR = 3;

const TVec STATS_POS = {0, 0};
const TVec PLAYER_POS = {0, 3};
const TVec WALL_POS = {10, 15};

const TVec STATS_SIZE = {15, 3};
const TVec MAP_SIZE = {100, 30};
const TVec MAP_DRAW_SIZE = {100, 30};

constexpr int PLAYER_SPEED = 1;

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
        
        MapBuffer map_buffer({'.', WALL_CH, '~', 'f'}, {0, WALL_PAIR, 0, 0});
        map = std::make_unique<Map>(MAP_SIZE, map_buffer);
        
        stats = std::make_unique<Stats>(STATS_SIZE, STATS_PAIR, STATS_POS);
        player = std::make_unique<Player>(PLAYER_CH, PLAYER_SPEED, PLAYER_PAIR, PLAYER_POS);

        map->set_cell(WALL, WALL_POS);
    }
};

exit_code loop(GameSession& session) {
    chtype_i key = getch();
    if (key == KEY_CTRLC) return EXIT;

    wnoutrefresh(stdscr);

    session.map->draw(MAP_DRAW_SIZE);
    session.player->update(key, session.map->get_maparr());
    session.stats->draw(key, session.player->get_pos());
     
    doupdate();
    napms(NAPMS);
    return CONTINUE;
}

int main() {
    SCREEN *s = nullptr; 
    s = newterm(NULL, stdout, stdin);
    set_term(s);

    if (has_colors() == FALSE) {
        printf("No color.");

        endwin();
        delscreen(s);
        return 0;
    }

    GameSession session;
    while (TRUE) {
        if (!loop(session)) break;
    }

    endwin();
    delscreen(s);
    return 0;
}