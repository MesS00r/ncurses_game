#ifndef COMMON_H_INCLUDED
#define COMMON_H_INCLUDED

#include <cstddef>

template<typename T, typename U>
T sc(U val) { return static_cast<T>(val); }

constexpr int KEY_CTRLC = 3;

typedef unsigned int env_type;
constexpr env_type NONE = 0;
constexpr env_type WALL = 1;

template<typename T>
struct Tvec {
    Tvec() : x(0), y(0) {}
    Tvec(T v_x, T v_y) : x(v_x), y(v_y) {}
    T x, y;

////////////////////////////////////////////////////////////

    Tvec operator + (const Tvec& other) {
        return {x + other.x, y + other.y};
    }

    Tvec operator + (const T num) {
        return {x + num, y + num};
    }

////////////////////////////////////////////////////////////

    Tvec operator - (const Tvec& other) {
        return {x - other.x, y - other.y};
    }

    Tvec operator - (const T num) {
        return {x - num, y - num};
    }
    
////////////////////////////////////////////////////////////

    Tvec operator * (const Tvec& other) {
        return {x * other.x, y * other.y};
    }

    Tvec operator * (const T num) {
        return {x * num, y * num};
    }
    
////////////////////////////////////////////////////////////

    Tvec operator / (const Tvec& other) {
        return {x / other.x, y / other.y};
    }

    Tvec operator / (const T num) {
        return {x / num, y / num};
    }
    
////////////////////////////////////////////////////////////

    Tvec operator % (const Tvec& other) {
        return {x % other.x, y % other.y};
    }

    Tvec operator % (const T num) {
        return {x % num, y % num};
    }

////////////////////////////////////////////////////////////

    Tvec& operator += (const Tvec& right) {
        x += right.x; y += right.y;
        return *this;
    }

    Tvec& operator += (const T num) {
        x += num; y += num;
        return *this;
    }

////////////////////////////////////////////////////////////

    Tvec& operator -= (const Tvec& right) {
        x -= right.x; y -= right.y;
        return *this;
    }

    Tvec& operator -= (const T num) {
        x -= num; y -= num;
        return *this;
    }

////////////////////////////////////////////////////////////

    Tvec& operator *= (const Tvec& right) {
        x *= right.x; y *= right.y;
        return *this;
    }

    Tvec& operator *= (const T num) {
        x *= num; y *= num;
        return *this;
    }

////////////////////////////////////////////////////////////

    Tvec& operator /= (const Tvec& right) {
        x /= right.x; y /= right.y;
        return *this;
    }

    Tvec& operator /= (const T num) {
        x /= num; y /= num;
        return *this;
    }

////////////////////////////////////////////////////////////

    Tvec& operator %= (const Tvec& right) {
        x %= right.x; y %= right.y;
        return *this;
    }

    Tvec& operator %= (const T num) {
        x %= num; y %= num;
        return *this;
    }

};

typedef Tvec<int> Tveci;
typedef Tvec<size_t> Tvecs;

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

    env_type& operator () (Tvecs& m_pos) {
        return map[m_pos.y * y + m_pos.x];
    }

    const env_type& operator () (Tvecs& m_pos) const {
        return map[m_pos.y * y + m_pos.x];
    }

    env_type& operator () (Tveci& m_pos) {
        return map[sc<size_t>(m_pos.y) * y + sc<size_t>(m_pos.x)];
    }

    const env_type& operator () (Tveci& m_pos) const {
        return map[sc<size_t>(m_pos.y) * y + sc<size_t>(m_pos.x)];
    }
};

#endif //COMMON_H_INCLUDED