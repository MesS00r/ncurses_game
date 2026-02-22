#ifndef TVECTOR_H_INCLUDED
#define TVECTOR_H_INCLUDED

#include <cstddef>

constexpr int KEY_CTRLC = 3;

typedef unsigned int env_type;
constexpr env_type NONE = 0;
constexpr env_type WALL = 1;

struct Tvec {
    Tvec(int v_x, int v_y): x(v_x), y(v_y) {}
    int x, y;

////////////////////////////////////////////////////////////

    Tvec operator + (const Tvec& other) {
        return {x + other.x, y + other.y};
    }

    Tvec operator + (const int num) {
        return {x + num, y + num};
    }

////////////////////////////////////////////////////////////

    Tvec operator - (const Tvec& other) {
        return {x - other.x, y - other.y};
    }

    Tvec operator - (const int num) {
        return {x - num, y - num};
    }
    
////////////////////////////////////////////////////////////

    Tvec operator * (const Tvec& other) {
        return {x * other.x, y * other.y};
    }

    Tvec operator * (const int num) {
        return {x * num, y * num};
    }
    
////////////////////////////////////////////////////////////

    Tvec operator / (const Tvec& other) {
        return {x / other.x, y / other.y};
    }

    Tvec operator / (const int num) {
        return {x / num, y / num};
    }
    
////////////////////////////////////////////////////////////

    Tvec operator % (const Tvec& other) {
        return {x % other.x, y % other.y};
    }

    Tvec operator % (const int num) {
        return {x % num, y % num};
    }

////////////////////////////////////////////////////////////

    Tvec& operator += (const Tvec& right) {
        x += right.x; y += right.y;
        return *this;
    }

    Tvec& operator += (const int num) {
        x += num; y += num;
        return *this;
    }

////////////////////////////////////////////////////////////

    Tvec& operator -= (const Tvec& right) {
        x -= right.x; y -= right.y;
        return *this;
    }

    Tvec& operator -= (const int num) {
        x -= num; y -= num;
        return *this;
    }

////////////////////////////////////////////////////////////

    Tvec& operator *= (const Tvec& right) {
        x *= right.x; y *= right.y;
        return *this;
    }

    Tvec& operator *= (const int num) {
        x *= num; y *= num;
        return *this;
    }

////////////////////////////////////////////////////////////

    Tvec& operator /= (const Tvec& right) {
        x /= right.x; y /= right.y;
        return *this;
    }

    Tvec& operator /= (const int num) {
        x /= num; y /= num;
        return *this;
    }

////////////////////////////////////////////////////////////

    Tvec& operator %= (const Tvec& right) {
        x %= right.x; y %= right.y;
        return *this;
    }

    Tvec& operator %= (const int num) {
        x %= num; y %= num;
        return *this;
    }

};

class Maparr {
private:
    const size_t x, y;
    env_type* map;
public:
    Maparr(const size_t size_x, const size_t size_y)
        : x(size_x), y(size_y), map(new env_type[x * y]) {}

    ~Maparr() { delete [] map; }

    env_type& operator () (size_t m_x, size_t m_y) {
        return map[m_y * y + m_x];
    }

    const env_type& operator () (size_t m_x, size_t m_y) const {
        return map[m_y * y + m_x];
    }
};

#endif //VECTORNC_H_INCLUDED