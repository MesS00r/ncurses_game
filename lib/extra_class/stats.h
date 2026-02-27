#ifndef STATS_H_INCLUDED
#define STATS_H_INCLUDED

#include <ncurses.h>
#include <common.h>
#include <panel.h>
#include <fstream> // IWYU pragma: keep
#include <unistd.h>

class Stats {
private:
    long pages, rss_kb = 0;
    WINDOW *stats_win;
    PANEL *stats;
public:
    Stats();
    Stats(int s_height, int s_width, int s_color_pair, int s_x = 0, int s_y = 0);
    ~Stats();

    void draw(int key, Tvec& p_pos);

    Stats(const Stats&) = delete;
    Stats& operator = (const Stats&) = delete;
};

#endif //STATS_H_INCLUDED