#include "player.h"

Player::Player() 
    : ch(0), color_pair(0), speed(0), pos(0, 0) {}

Player::Player(const int p_ch, int p_speed, const int p_color_pair, int p_x, int p_y)
    : ch(p_ch), color_pair(p_color_pair), speed(p_speed), pos(p_x, p_y) {}

void Player::update(int key) {
    switch (key) {
    case 'w': pos.y -= speed; break;
    case 's': pos.y += speed; break;
    case 'a': pos.x -= speed; break;
    case 'd': pos.x += speed; break;
    }

    attron(COLOR_PAIR(color_pair));
    mvaddch(pos.y, pos.x, static_cast<chtype>(ch));
    attroff(COLOR_PAIR(color_pair));
}

Tvec& Player::get_pos() {
    return pos;
}

void Player::set_pos(Tvec& new_pos) {
    pos = new_pos;
}