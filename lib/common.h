#ifndef COMMON_H_INCLUDED
#define COMMON_H_INCLUDED

#include <cstddef>
#include <vector>

template<typename T, typename U>
T sc(U val) { return static_cast<T>(val); }

constexpr int KEY_CTRLC = 3;
constexpr int KB = 1024;
constexpr int NAPMS = 30;

typedef unsigned int exit_code;
constexpr exit_code CONTINUE = 0;
constexpr exit_code EXIT = 1;

typedef unsigned int env_type;
constexpr env_type NONE = 0;
constexpr env_type WALL = 1;

struct Tvec {
    Tvec() : Tvec(0, 0) {}

    Tvec(int X, int Y)
    : x(X)
    , y(Y)
    {}

    int x, y;

    Tvec operator + (const Tvec& other)
    {
        return {x + other.x, y + other.y};
    }

    Tvec operator + (const int num)
    {
        return {x + num, y + num};
    }

    Tvec operator - (const Tvec& other)
    {
        return {x - other.x, y - other.y};
    }

    Tvec operator - (const int num)
    {
        return {x - num, y - num};
    }

    Tvec operator * (const Tvec& other)
    {
        return {x * other.x, y * other.y};
    }

    Tvec operator * (const int num)
    {
        return {x * num, y * num};
    }

    Tvec operator / (const Tvec& other)
    {
        return {x / other.x, y / other.y};
    }

    Tvec operator / (const int num)
    {
        return {x / num, y / num};
    }

    Tvec operator % (const Tvec& other)
    {
        return {x % other.x, y % other.y};
    }

    Tvec operator % (const int num)
    {
        return {x % num, y % num};
    }

    Tvec& operator += (const Tvec& other)
    {
        x += other.x; y += other.y;
        return *this;
    }

    Tvec& operator += (const int num)
    {
        x += num; y += num;
        return *this;
    }

    Tvec& operator -= (const Tvec& other)
    {
        x -= other.x; y -=other.y;
        return *this;
    }

    Tvec& operator -= (const int num)
    {
        x -= num; y -= num;
        return *this;
    }

    Tvec& operator *= (const Tvec& other)
    {
        x *= other.x; y *= other.y;
        return *this;
    }

    Tvec& operator *= (const int num)
    {
        x *= num; y *= num;
        return *this;
    }

    Tvec& operator /= (const Tvec& other)
    {
        x /= other.x; y /= other.y;
        return *this;
    }

    Tvec& operator /= (const int num)
    {
        x /= num; y /= num;
        return *this;
    }

    Tvec& operator %= (const Tvec& other)
    {
        x %= other.x; y %= other.y;
        return *this;
    }

    Tvec& operator %= (const int num)
    {
        x %= num; y %= num;
        return *this;
    }

    bool operator > (const Tvec other)
    {
        return x > other.x && y > other.y;
    }

    bool operator < (const Tvec other)
    {
        return x < other.x && y < other.y;
    }

    bool operator == (const Tvec other)
    {
        return x == other.x && y == other.y;
    }

    bool operator != (const Tvec other)
    {
        return x != other.x && y != other.y;
    }

    bool operator >= (const Tvec other)
    {
        return x >= other.x && y >= other.y;
    }

    bool operator <= (const Tvec other)
    {
        return x <= other.x && y <= other.y;
    }
};

struct Maparr {
    std::vector<env_type> map;
    size_t x, y;

    Maparr(size_t height, size_t width)
    : map(height * width)
    , x(width)
    , y(height)
    {}

    env_type& operator () (size_t X, size_t Y) 
    {
        return map[Y * y + X];
    }

    const env_type& operator () (size_t X, size_t Y) const 
    {
        return map[Y * y + X];
    }

    env_type& operator () (Tvec& pos) {
        return map[sc<size_t>(pos.y) * this->y + sc<size_t>(pos.x)];
    }

    const env_type& operator () (Tvec& pos) const 
    {
        return map[sc<size_t>(pos.y) * this->y + sc<size_t>(pos.x)];
    }
};

#endif //COMMON_H_INCLUDED