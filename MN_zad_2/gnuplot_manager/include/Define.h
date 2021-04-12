#ifndef __DEFS_H__
#define __DEFS_H__

class Range
{
public:
    double begin;
    double end;
    Range(double b, double e):begin(b),end(e){;};
};

template<class T>
class Point
{
public:
    T x;
    T y;
    Point(T x, T y):x(x),y(y){;};
};

#endif // __DEFS_H__
