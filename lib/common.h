#ifndef COMMON_H_INCLUDED
#define COMMON_H_INCLUDED

#include <cstddef>

template<typename T, typename U>
T sc(U val) { return static_cast<T>(val); }

constexpr int KEY_CTRLC = 3;

typedef unsigned int exit_code;
constexpr exit_code CONTINUE = 0;
constexpr exit_code EXIT = 1;

typedef unsigned int env_type;
constexpr env_type NONE = 0;
constexpr env_type WALL = 1;

struct Tvec {
    Tvec() : x(0), y(0) {}
    Tvec(int v_x, int v_y) : x(v_x), y(v_y) {}
    int x, y;

    Tvec operator + (const Tvec& other) {
        return {x + other.x, y + other.y};
    }

    Tvec operator + (const int num) {
        return {x + num, y + num};
    }

    Tvec operator - (const Tvec& other) {
        return {x - other.x, y - other.y};
    }

    Tvec operator - (const int num) {
        return {x - num, y - num};
    }

    Tvec operator * (const Tvec& other) {
        return {x * other.x, y * other.y};
    }

    Tvec operator * (const int num) {
        return {x * num, y * num};
    }

    Tvec operator / (const Tvec& other) {
        return {x / other.x, y / other.y};
    }

    Tvec operator / (const int num) {
        return {x / num, y / num};
    }

    Tvec operator % (const Tvec& other) {
        return {x % other.x, y % other.y};
    }

    Tvec operator % (const int num) {
        return {x % num, y % num};
    }

    Tvec& operator += (const Tvec& other) {
        x += other.x; y += other.y;
        return *this;
    }

    Tvec& operator += (const int num) {
        x += num; y += num;
        return *this;
    }

    Tvec& operator -= (const Tvec& other) {
        x -= other.x; y -=other.y;
        return *this;
    }

    Tvec& operator -= (const int num) {
        x -= num; y -= num;
        return *this;
    }

    Tvec& operator *= (const Tvec& other) {
        x *= other.x; y *= other.y;
        return *this;
    }

    Tvec& operator *= (const int num) {
        x *= num; y *= num;
        return *this;
    }

    Tvec& operator /= (const Tvec& other) {
        x /= other.x; y /= other.y;
        return *this;
    }

    Tvec& operator /= (const int num) {
        x /= num; y /= num;
        return *this;
    }

    Tvec& operator %= (const Tvec& other) {
        x %= other.x; y %= other.y;
        return *this;
    }

    Tvec& operator %= (const int num) {
        x %= num; y %= num;
        return *this;
    }

    bool operator > (const Tvec other) {
        return x > other.x && y > other.y;
    }

    bool operator < (const Tvec other) {
        return x < other.x && y < other.y;
    }

    bool operator == (const Tvec other) {
        return x == other.x && y == other.y;
    }

    bool operator != (const Tvec other) {
        return x != other.x && y != other.y;
    }

    bool operator >= (const Tvec other) {
        return x >= other.x && y >= other.y;
    }

    bool operator <= (const Tvec other) {
        return x <= other.x && y <= other.y;
    }
};

class Maparr {
private:
    env_type* map;
public:
    const int x, y;

    Maparr(const int size_x, const int size_y)
        : map(new env_type[sc<size_t>(size_x * size_y)]()), x(size_x), y(size_y) {}

    ~Maparr() { delete [] map; }

    env_type& operator () (int m_x, int m_y) {
        return map[m_y * y + m_x];
    }

    const env_type& operator () (int m_x, int m_y) const {
        return map[m_y * y + m_x];
    }

    env_type& operator () (Tvec& m_pos) {
        return map[m_pos.y * y + m_pos.x];
    }

    const env_type& operator () (Tvec& m_pos) const {
        return map[m_pos.y * y + m_pos.x];
    }
};

#endif //COMMON_H_INCLUDED