#ifndef COMMON_H_INCLUDED
#define COMMON_H_INCLUDED

#include <ncurses.h>
#include <vector>
#include <array>

template<typename T, typename U>
T sc(U val) { return static_cast<T>(val); }

constexpr int KEY_CTRLC = 3;
constexpr int KB        = 1024;
constexpr int NAPMS     = 30;

typedef bool exit_code;
constexpr exit_code EXIT     = FALSE;
constexpr exit_code CONTINUE = TRUE;

typedef unsigned int env_type;
constexpr env_type VOID  = 0;
constexpr env_type WALL  = 1;
constexpr env_type WATER = 2;
constexpr env_type TREE  = 3;

typedef int chtype_i;

struct TVec {
    TVec() : TVec(0, 0) {}

    TVec(int X, int Y)
    : x(X)
    , y(Y) {}

    int x, y;

    TVec operator + (const TVec& other) const {
        return {x + other.x, y + other.y};
    }

    TVec operator + (const int num) const {
        return {x + num, y + num};
    }

    TVec operator - (const TVec& other) const {
        return {x - other.x, y - other.y};
    }

    TVec operator - (const int num) const {
        return {x - num, y - num};
    }

    TVec operator * (const TVec& other) const {
        return {x * other.x, y * other.y};
    }

    TVec operator * (const int num) const {
        return {x * num, y * num};
    }

    TVec operator / (const TVec& other) const {
        return {x / other.x, y / other.y};
    }

    TVec operator / (const int num) const {
        return {x / num, y / num};
    }

    TVec operator % (const TVec& other) const {
        return {x % other.x, y % other.y};
    }

    TVec operator % (const int num) const {
        return {x % num, y % num};
    }

    TVec& operator += (const TVec& other) {
        x += other.x; y += other.y;
        return *this;
    }

    TVec& operator += (const int num) {
        x += num; y += num;
        return *this;
    }

    TVec& operator -= (const TVec& other) {
        x -= other.x; y -=other.y;
        return *this;
    }

    TVec& operator -= (const int num) {
        x -= num; y -= num;
        return *this;
    }

    TVec& operator *= (const TVec& other) {
        x *= other.x; y *= other.y;
        return *this;
    }

    TVec& operator *= (const int num) {
        x *= num; y *= num;
        return *this;
    }

    TVec& operator /= (const TVec& other) {
        x /= other.x; y /= other.y;
        return *this;
    }

    TVec& operator /= (const int num) {
        x /= num; y /= num;
        return *this;
    }

    TVec& operator %= (const TVec& other) {
        x %= other.x; y %= other.y;
        return *this;
    }

    TVec& operator %= (const int num) {
        x %= num; y %= num;
        return *this;
    }
};

struct MapArr {
    std::vector<env_type> map;
    TVec                  size;

    MapArr() : MapArr({0, 0}) {}
    MapArr(TVec SIZE)
    : map(sc<size_t>(SIZE.x * SIZE.y))
    , size(SIZE) {}

    env_type& operator () (const TVec& pos) {
        return map[sc<size_t>(pos.y * size.x + pos.x)];
    }

    const env_type& operator () (const TVec& pos) const {
        return map[sc<size_t>(pos.y * size.x + pos.x)];
    }

    bool is_inside(const TVec& other) const {
        return other.x >= 0 && other.y >= 0 
        && other.x < size.x && other.y < size.y;
    }
};

struct MapBuffer {
    std::array<chtype_i, 4> chs;
    std::array<int, 4>      pairs;

    MapBuffer() : MapBuffer({0, 0 ,0, 0}, {0, 0 ,0, 0}) {}
    MapBuffer(
      const std::array<chtype_i, 4>& CHS
    , const std::array<int, 4>& PAIRS)
    : chs(CHS)
    , pairs(PAIRS) {}
};

#endif //COMMON_H_INCLUDED