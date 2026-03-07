#include "map.h"

Map::Map(const TVec &size, const MapBuffer &buffer)
: m_map(size)
, m_buffer(buffer) {}

static void draw_tile(const TVec &pos, int color_pair, chtype_i ch) {
    attron (COLOR_PAIR(color_pair));
    mvaddch(pos.y, pos.x, sc<chtype>(ch));
    attroff(COLOR_PAIR(color_pair));
}

void Map::draw(const TVec &size) {
    for (int i = 0; i < size.x * size.y; i++) {
        int x = i % size.x;
        int y = i / size.x;
        env_type ch = m_map({x, y});

        switch (ch) {
        case WALL:
        draw_tile({x, y}
        , m_buffer.pairs[WALL], m_buffer.chs[WALL]);
        break;

        case WATER:
        draw_tile({x, y}
        , m_buffer.pairs[WATER], m_buffer.chs[WATER]);
        break;

        case TREE:
        draw_tile({x, y}
        , m_buffer.pairs[TREE], m_buffer.chs[TREE]);
        break;

        default:
        draw_tile({x, y}
        , m_buffer.pairs[VOID], m_buffer.chs[VOID]);
        break;
        }
    }
}

env_type Map::get_cell(const TVec &pos) { return m_map(pos); }

const MapArr &Map::get_maparr() { return m_map; }

void Map::set_cell(env_type type, const TVec &pos) { m_map(pos) = type; }