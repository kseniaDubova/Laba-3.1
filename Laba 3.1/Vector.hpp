//
//  Vector.hpp
//  Laba 3.1
//
//  Created by Ксения Дубова on 14.09.2022.
//

#ifndef Vector_hpp
#define Vector_hpp
#include "ESetErrors.hpp"
#include <stdio.h>
#include <cmath>
const int resolution=15;


class Vector
{
private:
    int** _matrix;
    int _vertical, _horizontal;
    int min (int a, int b);
    int max (int a, int b);
    void make_line(int min_x, int max_x, int min_y, int max_y);
    void make_different_lines(int i, int j, int n, int min_x, int max_x, int min_y, int max_y, bool flag);
public:
    Vector(int horizontal=0, int vertical =0, int x1=0, int y1 =0, int x2=0, int y2=0);
    int get_horizontal() const;
    void set_horizontal(int value);
    int get_vertical() const;
    void set_vertical(int value);
    Vector(const Vector& a);
    ~Vector();
//    void operator ()() = 0;
    Vector& operator *(const Vector& obg);
    Vector& operator +(const Vector& obg);
//    bool operator *();
//    bool operator +();
    Vector& operator !();
    double coefficient_of_fullness();
    friend ostream& operator << (ostream& s, const Vector& obj);

};

#endif /* Vector_hpp */
