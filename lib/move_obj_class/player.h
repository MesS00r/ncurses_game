#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <ncurses.h>
#include <common.h>

class Player{
private:
    chtype m_ch;
    int m_color_pair, m_speed;
    Tvec m_pos;
public:
    Player() : Player(0, 0, 0) {}
    Player(chtype ch, int speed, int color_pair, int x = 0, int y = 0);

    void update(int key, Maparr& map);
    Tvec& get_pos();
    void set_pos(Tvec& pos);
    void set_pos(int x, int y);

    Player(const Player&) = delete;
    Player& operator = (const Player&) = delete;

    ~Player() = default;
    Player(Player&&) = default;
    Player& operator = (Player&&) = default;
};

#endif //PLAYER_H_INCLUDED