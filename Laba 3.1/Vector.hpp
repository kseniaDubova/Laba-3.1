

#ifndef Vector_hpp
#define Vector_hpp
#include "ESetErrors.hpp"
#include <stdio.h>
#include <cmath>

template<typename T>
class Vector
{
private:
    T** _matrix;
    int _resolution;
    int min (int a, int b);
    int max (int a, int b);
    void make_line(int min_x, int max_x, int min_y, int max_y, int flag_1,int flag_2);
public:
    Vector(int resolution=0);
    int get_resolution() const;
    void set_resolution(int value);
    void set_line(int x1, int y1, int x2, int y2);
    Vector(const Vector& a);
    ~Vector();
    T operator ()(int x, int y);
    void operator ()(int x, int y, T value);
    Vector& operator *(const Vector& obg);
    Vector& operator +(const Vector& obg);
    Vector& operator *(T value);
    Vector& operator +(T value);
    friend Vector& operator *(const T value, Vector& obj);
    friend Vector& operator +(const T value, Vector& obj);
    Vector& operator !();
    double coefficient_of_fullness();
    friend ostream& operator << (ostream& s, const Vector& obj);

};

#endif /* Vector_hpp */
