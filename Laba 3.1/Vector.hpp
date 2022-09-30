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
const int resolution=15;


class Vector
{
private:
    int** _matrix;
    int _vertical, _horizontal;
public:
    Vector(int horizontal=2, int vertical =2, int x1=0, int y1 =0, int x2=0, int y2=0);
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
    friend ostream& operator << (ostream& s, const Vector& obj);

};

#endif /* Vector_hpp */
