#include "map.h"

Map::Map(int width, int height, chtype wallch, int wall_color_pair) 
: m_map(width, height)
, m_wallch(wallch)
, m_wall_color_pair(wall_color_pair)
{}

static void draw_tile(int x, int y, int color_pair, chtype ch)
{
    attron(COLOR_PAIR(color_pair));
    mvaddch(x, y, ch);
    attroff(COLOR_PAIR(color_pair));
}

void Map::draw(int width, int height)
{
    for(int i = 0; i <  width * height; i++)
    {
        int x = i % width;
        int y = i / width;
        env_type ch = m_map(x, y);
     
        switch (ch)
        {
        case WALL: draw_tile(x, y, m_wall_color_pair, m_wallch); break;
        default: break;
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