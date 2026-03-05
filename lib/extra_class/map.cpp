#include "map.h"

Map::Map(const Tvec& size, chtype_i wallch, int wall_color_pair) 
: m_map(size)
, m_wallch(wallch)
, m_wall_color_pair(wall_color_pair) {}

static void draw_tile(const Tvec& pos, int color_pair, chtype_i ch) {
    attron(COLOR_PAIR(color_pair));
    mvaddch(pos.y, pos.x, sc<chtype>(ch));
    attroff(COLOR_PAIR(color_pair));
}

void Map::draw(const Tvec& size) {
    for(int i = 0; i <  size.x * size.y; i++) {
        int x = i % size.x;
        int y = i / size.x;
        env_type ch = m_map(x, y);
     
        switch (ch) {
        case WALL: draw_tile({x, y}, m_wall_color_pair, m_wallch); break;
        default: break;
        }
    }
}

env_type Map::get_cell(const Tvec& pos) { 
    return m_map(pos);
}

const Maparr& Map::get_maparr() { 
    return m_map;
}

void Map::set_cell(env_type type, const Tvec& pos) { 
    m_map(pos) = type;
}