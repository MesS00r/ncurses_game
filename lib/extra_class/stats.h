#ifndef STATS_H_INCLUDED
#define STATS_H_INCLUDED

#include <ncurses.h>
#include <common.h>
#include <fstream> // IWYU pragma: keep
#include <unistd.h>

class Stats {
private:
    WINDOW *m_stats_win;
public:
    Stats() : Stats(1, 1, 0) {}
    Stats(int width, int height, int color_pair, int x = 0, int y = 0);
    ~Stats();

    void draw(chtype key, Tvec& pos);

    Stats(const Stats&) = delete;
    Stats& operator = (const Stats&) = delete;

    Stats(Stats&&) = default;
    Stats& operator = (Stats&&) = delete;
};

#endif //STATS_H_INCLUDED