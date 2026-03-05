#include "stats.h"

Stats::Stats(const Tvec& size, int color_pair, const Tvec& pos)
: m_stats_win(newwin(size.y, size.x, pos.y, pos.x)) {
    wbkgd(m_stats_win, COLOR_PAIR(color_pair) | A_BOLD);
}

Stats::~Stats() {
    if (m_stats_win) delwin(m_stats_win);
}

static long check_mem () {
    long pages = 0; 
    static long rss_kb = 0;

    std::ifstream statm("/proc/self/statm");
    if (statm >> pages >> pages) {
        rss_kb = pages * sysconf(_SC_PAGESIZE) / KB;
    }
    statm.close();
    
    return  rss_kb;
}

void Stats::draw(chtype_i key, const Tvec& pos) {
    long rss_kb = 0;
    rss_kb = check_mem();

    mvwprintw(m_stats_win, 0, 0, "mem: %ldKB ", rss_kb);
    mvwprintw(m_stats_win, 1, 0, "x,y: %d,%d ", pos.x, pos.y);
    if (key != -1) mvwprintw(m_stats_win, 2, 0, "key: %c:%d ", key, key);

    touchwin(m_stats_win);
    wnoutrefresh(m_stats_win);
    doupdate();
}