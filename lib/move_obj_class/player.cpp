#include "player.h"

Player::Player(chtype ch, int speed, int color_pair, int x, int y)
: m_ch(ch)
, m_color_pair(color_pair)
, m_speed(speed)
, m_pos(x, y)
{}

static void draw(Tvec& prev_pos, Tvec& pos, int color_pair, chtype ch)
{
    attron(COLOR_PAIR(color_pair));
    mvaddch(prev_pos.y, prev_pos.x, ' ');
    mvaddch(pos.y, pos.x, ch);
    attroff(COLOR_PAIR(color_pair));
}

static const Tvec move(int key)
{
    switch (key)
    {
    case 'w': case 'W': return {0, -1};
    case 's': case 'S': return {0, 1};
    case 'a': case 'A': return {-1, 0};
    case 'd': case 'D': return {1, 0};
    default: return {0, 0};
    }
}

static bool check_col(Tvec& cell, Maparr& map)
{
    if (!(cell < Tvec(map.x, map.y))) return true;
    if (!(cell >= Tvec(0, 0))) return true;
    if (map(cell) != NONE) return true;
    return false;
}

void Player::update(int key, Maparr& map)
{
    Tvec direction, prev_pos, next_cell;

    direction = move(key);
    prev_pos = m_pos;
    next_cell = m_pos + direction;
    
    if (check_col(next_cell, map)) return;
    
    m_pos += direction * m_speed;
    draw(prev_pos, m_pos, m_color_pair, m_ch);
}

Tvec& Player::get_pos()
{ 
    return m_pos; 
}

void Player::set_pos(Tvec& pos)
{ 
    m_pos = pos; 
}

void Player::set_pos(int x, int y)
{
    m_pos.x = x;
    m_pos.y = y;
}