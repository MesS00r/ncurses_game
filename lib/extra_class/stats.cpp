#include "stats.h"

Stats::Stats() : stats_win(nullptr), stats(nullptr) {}

Stats::Stats(int s_height, int s_width, int s_color_pair, int s_x, int s_y) {
    stats_win = newwin(s_height, s_width, s_x, s_y);
    wbkgd(stats_win, COLOR_PAIR(s_color_pair) | A_BOLD);
    stats = new_panel(stats_win);
}

Stats::~Stats() {
    if (!isendwin()) {
        if (stats) del_panel(stats);
        if (stats_win) delwin(stats_win);
    }

    stats = nullptr;
    stats_win = nullptr;
}

void Stats::draw(int key, Tvec& p_pos) {
    std::ifstream statm("/proc/self/statm");
    if (statm >> pages >> pages) {
        rss_kb = pages * sysconf(_SC_PAGESIZE) / 1024;
        mvwprintw(stats_win, 0, 0, "mem: %ldKB ", rss_kb);
    }
    statm.close();

    mvwprintw(stats_win, 1, 0, "x,y: %d,%d ", p_pos.x, p_pos.y);
    if (key != -1) mvwprintw(stats_win, 2, 0, "key: %c:%d ", key, key);

    // touchwin(stats_win);
    update_panels();
    doupdate();
}