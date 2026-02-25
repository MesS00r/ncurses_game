#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <ncurses.h>
#include <common.h>

class Player{
private:
    const int ch, color_pair;
    int speed;
    Tvec pos;
public:
    Player();
    Player(const int p_ch, int p_speed, const int p_color_pair, int p_x = 0, int p_y = 0);

    void update(int key, Maparr& map);
    Tvec& get_pos();
    void set_pos(Tvec& new_pos);
    void set_pos(int new_x, int new_y);

    Player(const Player&) = delete;
    Player& operator = (const Player&) = delete;
};

#endif //PLAYER_H_INCLUDED