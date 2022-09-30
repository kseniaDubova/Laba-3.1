
//
//  Vector.cpp
//  Laba 3.1
//
//  Created by Ксения Дубова on 14.09.2022.
//

#include "Vector.hpp"

int max (int a, int b)
{ return (a>b) ? a: b;}
int min (int a, int b)
{ return (a<b) ? a: b;}

Vector::Vector(int horizontal, int vertical,int x1, int y1, int x2, int y2)
{
    set_horizontal(horizontal);
    set_vertical(vertical);
    _matrix = new int * [_horizontal];
    for (int i = 0; i<_horizontal; i++)
    {
        _matrix[i]= new int [_vertical];
    }
    for (int i = 0; i<_horizontal; i++)
    {
       for (int j = 0; j<_vertical; j++)
       {
           if ((i+1==y1&&j+1==x1)||(i+1==y2&&j+1==x2))
               _matrix[i][j] = 1;
           else _matrix[i][j] = 0;
//           cout << _matrix[i][j];
       }
//        cout<<endl;
    }
}
void Vector:: set_vertical(int value)
{
    _vertical=value;
}
void Vector:: set_horizontal(int value)
{
    _horizontal=value;
}
int Vector:: get_vertical() const
{
    return _vertical;
}
int Vector:: get_horizontal() const
{
    return _horizontal;
}
Vector::Vector(const Vector& a)
{
    _horizontal=a._horizontal;
    _vertical=a._vertical;
    _matrix = new int * [_horizontal];
    for (int i = 0; i<_vertical; i++)
    {
        _matrix[i]= new int [_horizontal];
    }
    for (int i = 0; i<_vertical; i++)
    {
       for (int j = 0; j<_horizontal; j++)
       {
           _matrix[i][j]=a._matrix[i][j];
       }
        
    }
    
}
Vector::~Vector()
{
    for (int i = 0; i<_horizontal; i++)
    {
       delete _matrix[i];
    }
    delete [] _matrix;
}
Vector& Vector:: operator+(const Vector& obj)
{
    return *this;
}
Vector& Vector:: operator*(const Vector& obj)
{
    return *this;
}
Vector& Vector:: operator !()
{
    for (int i =0; i<_horizontal; i++)
    {
        for (int j=0; j<_vertical; j++)
        {
            if (_matrix[i][j]==1)
                _matrix[i][j]=0;
            else _matrix[i][j]=1;
        }
    }
    return *this;
}
double Vector:: coefficient_of_fullness()
{
    int counter = 0;
    for (int i =0; i<_horizontal; i++)
    {
        for (int j=0; j<_vertical; j++)
        {
            if (_matrix[i][j]==1) counter++;
        }
    }
    return _vertical*_horizontal/counter;
}
ostream& operator << (ostream& s, const Vector& obj)
{
   for (int i =obj._horizontal-1; i>=0; i--)
    {
        for (int j =0; j<obj._vertical; j++)
            s << obj._matrix[i][j];
        s << endl;
    }
    return s;
}
