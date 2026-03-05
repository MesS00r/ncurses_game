#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#include <ncurses.h>
#include <common.h>

class Map {
private:
    Maparr m_map;
    chtype_i m_wallch;
    int m_wall_color_pair;
public:
    Map() : Map({0, 0}, 0, 0) {}
    Map(const Tvec& size, chtype_i wallch, int wall_color_pair);

    void draw(const Tvec& size);
    env_type get_cell(const Tvec& pos);
    const Maparr& get_maparr();
    void set_cell(env_type type, const Tvec& pos);

    Map(const Map&) = delete;
    Map& operator = (const Map&) = delete;

    ~Map() = default;
    Map(Map&&) = default;
    Map& operator = (Map&&) = delete;
};

#endif //MAP_H_INCLUDED