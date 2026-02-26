#include <move_obj_class/player.h>
#include <extra_class/map.h>
#include <fstream>
#include <unistd.h>

constexpr int PLAYER_CH = 'P';
constexpr int PLAYER_PAIR = 1;
constexpr int WALL_CH = '#';
constexpr int WALL_PAIR = 2;
constexpr int STATS_PAIR = 3;

void end_game(SCREEN *s, WINDOW *w);

int main() {
    SCREEN *s;
    s = newterm(NULL, stdout, stdin);
    set_term(s);

    if (has_colors() == FALSE) {
        printf("No color.");
        end_game(s, NULL);
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

    long pages = 0, rss_kb;
    WINDOW *stats = newwin(3, 15, 0, 0);
    wbkgd(stats, COLOR_PAIR(STATS_PAIR) | A_BOLD);

    int key;
    Player player(PLAYER_CH, 1, PLAYER_PAIR);

    Map map(100, 100, WALL_CH, WALL_PAIR);
    map.set_cell(WALL, 10, 10);

    while (TRUE) {
        key = getch();
        if (key == KEY_CTRLC) {
            end_game(s, stats);
            return 0;
        }

        map.draw(100, 100);
        player.update(key, map.get_maparr());

        wnoutrefresh(stdscr);

        std::ifstream statm("/proc/self/statm");
        if (statm >> pages >> pages) {
            rss_kb = pages * sysconf(_SC_PAGESIZE) / 1024;
            mvwprintw(stats, 0, 0, "mem: %ldKB ", rss_kb);
        }
        statm.close();

        mvwprintw(stats, 1, 0, "x,y: %d,%d ", player.get_pos().x, player.get_pos().y);
        if (key != -1) mvwprintw(stats, 2, 0, "key: %c:%d ", key, key);

        touchwin(stats);
        wnoutrefresh(stats);
        doupdate();

        napms(30);
    }
    
    end_game(s, stats);
    return 0;
}

void end_game(SCREEN *s, WINDOW *w) {
    delwin(w);
    endwin();
    delscreen(s);
}