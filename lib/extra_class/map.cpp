#include "map.h"

Map::Map()
    : map(0, 0), wallch(0), wall_color_pair(0) {}

Map::Map(const int m_size_x, const int m_size_y, const int m_wallch, const int m_wall_color_pair) 
    : map(m_size_x, m_size_y), wallch(m_wallch), wall_color_pair(m_wall_color_pair) {}

void Map::draw(int w_size_x, int w_size_y) {
    for(int i = 0; i < w_size_y; i++) {
        for(int j = 0; j < w_size_x; j++) {
            env_type ch = map(j, i);
            switch (ch) {
            case WALL:
                attron(COLOR_PAIR(wall_color_pair));
                mvaddch(i, j, sc<chtype>(wallch));
                attroff(COLOR_PAIR(wall_color_pair));
            }
        }
    }
}

env_type Map::get_cell(int c_x, int c_y) {
    return map(c_x, c_y);
}

env_type Map::get_cell(Tvec c_pos) {
    return map(c_pos);
}

Maparr& Map::get_maparr() {
    return  map;
}

void Map::set_cell(env_type type, int c_x, int c_y) {
    map(c_x, c_y) = type;
}

void Map::set_cell(env_type type, Tvec c_pos) {
    map(c_pos) = type;
}

void Map::del_map() {

}