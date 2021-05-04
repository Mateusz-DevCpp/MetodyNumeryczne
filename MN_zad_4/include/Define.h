#ifndef __DEFS_H__
#define __DEFS_H__

#include <iostream>
#include <sstream>

template<class T>
class Punkt
{
public:
    T x;
    T y;

    Punkt():x(0),y(0)
    {

    }

    Punkt(T a, T b):x(a),y(b)
    {

    }

    void print()
    {
        std::cout << x << " : " << y << std::endl;
    }

    std::string toString()
    {
        std::stringstream ss;
        ss << x << " : " << y;
        return ss.str();
    }
};

#endif // __DEFS_H__
