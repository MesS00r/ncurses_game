#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <ncurses.h>
#include <common.h>

class Player{
private:
    chtype_i m_ch;
    int m_color_pair, m_speed;
    Tvec m_pos;
public:
    Player() : Player(0, 0, 0, {0, 0}) {}
    Player(chtype_i ch, int speed, int color_pair, const Tvec& pos);

    void update(int key, const Maparr& map);
    const Tvec& get_pos();
    void set_pos(const Tvec& pos);

    Player(const Player&) = delete;
    Player& operator = (const Player&) = delete;

    ~Player() = default;
    Player(Player&&) = default;
    Player& operator = (Player&&) = default;
};

#endif //PLAYER_H_INCLUDED