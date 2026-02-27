#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#include <ncurses.h>
#include <common.h>

class Map {
private:
    Maparr map;
    const int wallch, wall_color_pair;
public:
    Map();
    Map(const int m_size_x, const int m_size_y,
        const int m_wallch, const int m_wall_color_pair);

    void draw(int w_size_x, int w_size_y);
    env_type get_cell(int c_x, int c_y);
    env_type get_cell(Tvec& c_pos);
    Maparr& get_maparr();
    void set_cell(env_type type, int c_x, int c_y);
    void set_cell(env_type type, Tvec& c_pos);
    void del_map();

    Map(const Map&) = delete;
    Map& operator = (const Map&) = delete;
};

#endif //MAP_H_INCLUDED