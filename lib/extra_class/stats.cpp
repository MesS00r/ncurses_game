#include "stats.h"

Stats::Stats() : stats_win(nullptr) {}

Stats::Stats(int s_height, int s_width, int s_color_pair, int s_x, int s_y) {
    stats_win = newwin(s_height, s_width, s_y, s_x);
    wbkgd(stats_win, COLOR_PAIR(s_color_pair) | A_BOLD);
}

Stats::~Stats() { if (stats_win) delwin(stats_win); }

void Stats::draw(int key, Tvec& p_pos) {
    std::ifstream statm("/proc/self/statm");
    if (statm >> pages >> pages) {
        rss_kb = pages * sysconf(_SC_PAGESIZE) / 1024;
        mvwprintw(stats_win, 0, 0, "mem: %ldKB ", rss_kb);
    }
    statm.close();

    mvwprintw(stats_win, 1, 0, "x,y: %d,%d ", p_pos.x, p_pos.y);
    if (key != -1) mvwprintw(stats_win, 2, 0, "key: %c:%d ", key, key);

    touchwin(stats_win);
    wnoutrefresh(stats_win);
    doupdate();
}