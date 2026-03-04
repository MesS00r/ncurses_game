#include "map.h"

Map::Map(int size_x, int size_y, int wallch, int wall_color_pair) 
: m_map(size_x, size_y)
, m_wallch(wallch)
, m_wall_color_pair(wall_color_pair)
{}

static void draw_tile(int x, int y, int color_pair, chtype ch)
{
    attron(COLOR_PAIR(color_pair));
    mvaddch(x, y, ch);
    attroff(COLOR_PAIR(color_pair));
}

void Map::draw(int height, int width)
{
    for(int y = 0; y <  height; y++)
    {
        for(int x = 0; x < width; x++)
        {
            env_type ch = m_map(x, y);

            switch (ch)
            {
            case WALL: draw_tile(x, y, m_wall_color_pair, sc<chtype>(m_wallch)); break;
            }
        }
    }
}

env_type Map::get_cell(int x, int y)
{ 
    return m_map(x, y);
}

env_type Map::get_cell(Tvec& pos)
{ 
    return m_map(pos);
}

Maparr& Map::get_maparr()
{ 
    return m_map;
}

void Map::set_cell(env_type type, int x, int y)
{ 
    m_map(x, y) = type;
}

void Map::set_cell(env_type type, Tvec& pos)
{ 
    m_map(pos) = type;
}