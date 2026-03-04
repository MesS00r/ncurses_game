#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#include <ncurses.h>
#include <common.h>

class Map {
private:
    Maparr m_map;
    chtype m_wallch;
    int m_wall_color_pair;
public:
    Map() : Map(0, 0, 0, 0) {}
    Map(int width, int height, chtype wallch, int wall_color_pair);

    void draw(int height, int width);
    env_type get_cell(int x, int y);
    env_type get_cell(Tvec& pos);
    Maparr& get_maparr();
    void set_cell(env_type type, int x, int y);
    void set_cell(env_type type, Tvec& pos);

    Map(const Map&) = delete;
    Map& operator = (const Map&) = delete;

    ~Map() = default;
    Map(Map&&) = default;
    Map& operator = (Map&&) = delete;
};

#endif //MAP_H_INCLUDED