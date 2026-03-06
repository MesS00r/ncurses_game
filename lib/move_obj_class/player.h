#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <ncurses.h>
#include <common.h>

class Player{
private:
    chtype_i m_ch;
    int m_colorp;
    int m_speed;
    TVec m_pos;
public:
    Player() : Player(0, 0, 0, {0, 0}) {}
    Player(chtype_i ch, int speed, int colorp, const TVec& pos);

    void update(int key, const MapArr& map);
    const TVec& get_pos();
    void set_pos(const TVec& pos);

    Player(const Player&) = delete;
    Player& operator = (const Player&) = delete;

    ~Player() = default;
    Player(Player&&) = default;
    Player& operator = (Player&&) = default;
};

#endif //PLAYER_H_INCLUDED