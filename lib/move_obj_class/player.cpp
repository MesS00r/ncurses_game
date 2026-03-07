#include "player.h"

Player::Player(chtype_i ch, int speed, int colorp, const TVec& pos)
: m_ch(ch)
, m_colorp(colorp)
, m_speed(speed)
, m_pos(pos) {}

static void draw(const TVec& pos, int color_pair, chtype_i ch) {
    attron(COLOR_PAIR(color_pair));
    mvaddch(pos.y, pos.x, sc<chtype>(ch));
    attroff(COLOR_PAIR(color_pair));
}

static const TVec move(int key) {
    switch (key) {
    case 'w': case 'W': return {0, -1};
    case 's': case 'S': return {0, 1};
    case 'a': case 'A': return {-1, 0};
    case 'd': case 'D': return {1, 0};
    default: return {0, 0};
    }
}

static bool check_col(const TVec& cell, const MapArr& map) {
    if (!map.is_inside(cell)) return TRUE;
    if (map(cell) != VOID) return TRUE;
    return FALSE;
}

void Player::update(int key, const MapArr& map) {
    TVec direction, next_cell;

    direction = move(key);
    next_cell = m_pos + direction;
    
    if (!check_col(next_cell, map)) {
        m_pos += direction * m_speed;
    }

    draw(m_pos, m_colorp, m_ch);
}

const TVec& Player::get_pos() { return m_pos; }

void Player::set_pos(const TVec& pos) { m_pos = pos; }