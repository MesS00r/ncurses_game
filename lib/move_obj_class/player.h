#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <ncurses.h>
#include <common.h>
#include <extra_class/map.h>

class Player : public Map {
private:
    const int ch, color_pair;
    int speed;
    Tvec pos;
public:
    Player();
    Player(const int p_ch, int p_speed, const int p_color_pair, int p_x = 0, int p_y = 0);

    void update(int key);
    Tvec& get_pos();
    void set_pos(Tvec& new_pos);

    Player(const Player&) = delete;
    Player& operator = (const Player&) = delete;
};

#endif //PLAYER_H_INCLUDED