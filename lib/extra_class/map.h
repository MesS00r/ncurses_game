#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#include <common.h>
#include <ncurses.h>

class Map {
private:
    MapArr    m_map;
    MapBuffer m_buffer;
public:
    Map() : Map({0, 0}, {{0, 0, 0}, {0, 0, 0}}) {}
    Map(const TVec &size, const MapBuffer &buffer);

    void draw(const TVec &size);
    env_type get_cell(const TVec &pos);
    const MapArr& get_maparr();
    void set_cell(env_type type, const TVec &pos);

    Map(const Map &) = delete;
    Map &operator = (const Map &) = delete;

    ~Map() = default;
    Map(Map &&) = default;
    Map &operator = (Map &&) = default;
};

#endif // MAP_H_INCLUDED