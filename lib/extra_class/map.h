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
    Map(const size_t m_size_x, const size_t m_size_y,
        const int m_wallch, const int m_wall_color_pair);

    void draw(size_t w_size_x, size_t w_size_y);
    env_type get_cell(size_t c_x, size_t c_y);
    env_type get_cell(Tvecs c_pos);
    Maparr& get_maparr();
    void set_cell(env_type type, size_t c_x, size_t c_y);
    void set_cell(env_type type, Tvecs c_pos);

    Map(const Map&) = delete;
    Map& operator = (const Map&) = delete;
};

#endif //MAP_H_INCLUDED