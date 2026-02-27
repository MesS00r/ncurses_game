#include "player.h"

Player::Player() 
    : ch(0), color_pair(0), speed(0), pos(0, 0) {}

Player::Player(const int p_ch, int p_speed, const int p_color_pair, int p_x, int p_y)
    : ch(p_ch), color_pair(p_color_pair), speed(p_speed), pos(p_x, p_y) {}

void Player::update(int key, Maparr& map) {
    Tvec direction;
    Tvec prev_pos;

    switch (key) {
    case 'w': case 'W': direction.y = -1; break;
    case 's': case 'S': direction.y = 1; break;
    case 'a': case 'A': direction.x = -1; break;
    case 'd': case 'D': direction.x = 1; break;
    }

    prev_pos = pos;
    Tvec next_cell = (pos + direction);

    if (!(next_cell < Tvec(map.x, map.y))) return;
    if (!(next_cell >= Tvec(0, 0))) return;
    if (map(next_cell) == NONE) pos += direction * speed;

    attron(COLOR_PAIR(color_pair));
    mvaddch(prev_pos.y, prev_pos.x, ' ');
    mvaddch(pos.y, pos.x, sc<chtype>(ch));
    attroff(COLOR_PAIR(color_pair));
}

Tvec& Player::get_pos() {
    return pos;
}

void Player::set_pos(Tvec& new_pos) {
    pos = new_pos;
}

void Player::set_pos(int new_x, int new_y) {
    pos.x = new_x; pos.y = new_y;
}