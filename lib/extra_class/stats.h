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
    Stats() : Stats({1, 1}, 0, {0, 0}) {}
    Stats(const Tvec& size, int color_pair, const Tvec& pos);
    ~Stats();

    void draw(chtype_i key, const Tvec& pos);

    Stats(const Stats&) = delete;
    Stats& operator = (const Stats&) = delete;

    Stats(Stats&&) = default;
    Stats& operator = (Stats&&) = delete;
};

#endif //STATS_H_INCLUDED