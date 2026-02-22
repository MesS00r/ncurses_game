#include "map.h"

Map::Map()
    : map(0, 0), wallch(0), wall_color_pair(0){}

Map::Map(const size_t m_size_x, const size_t m_size_y, const int m_wallch, const int m_wall_color_pair) 
    : map(m_size_x, m_size_y), wallch(m_wallch), wall_color_pair(m_wall_color_pair) {
        
    }

void Map::draw(size_t w_size_x, size_t w_size_y) {
    for(size_t i = 0; i < w_size_y; i++) {
        for(size_t j = 0; j < w_size_x; j++) {
            env_type ch = map(j, i);
            switch (ch) {
            case WALL:
                attron(COLOR_PAIR(wall_color_pair));
                mvaddch(i, j, static_cast<chtype>(wallch));
                attroff(COLOR_PAIR(wall_color_pair));
            }
        }
    }
}

env_type Map::get_cell(size_t c_x, size_t c_y) {
    return map(c_x, c_y);
}

void Map::set_cell(env_type type, size_t c_x, size_t c_y) {
    map(c_x, c_y) = type;
}