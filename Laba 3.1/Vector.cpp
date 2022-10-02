
//
//  Vector.cpp
//  Laba 3.1
//
//  Created by Ксения Дубова on 14.09.2022.
//

#include "Vector.hpp"

int Vector:: max (int a, int b)
{ return (a>b) ? a: b;}
int Vector:: min (int a, int b)
{ return (a<b) ? a: b;}
void Vector:: make_different_lines(int i, int j, int n, int min_x, int max_x, int min_y, int max_y, bool flag_1,bool flag_2)
{
    if (flag_1)
    {
        while (i<max_x-1)
        {
            int count =1;
            while (count<=n)
           {
               if (flag_2)
                   _matrix[j][i]=1;
               else _matrix[i][j]=1;
                count++;
                i++;
               
           }
            j++;
            if (j==max_y-1)
                j--;
            count=0;
        }
    }
    else
    {
        while (i>min_x-1)
        {
            int count =1;
            while (count<=n)
           {
               if (flag_2)
                   _matrix[j][i]=1;
               else _matrix[i][j]=1;
                count++;
                i--;
               
           }
            j++;
            if (j==max_y-1)
                j--;
            count=0;
        }
    }
}
void Vector:: make_line(int min_x, int max_x, int min_y, int max_y,bool flag)
{
    int n;
    if (flag)
        {
            int i = min_x-1, j=min_y-1;
            if (max_x-min_x>=max_y-min_y)
            {
                n = ceil((max_x-min_x)/(max_y-min_y));
                if (n==0)
                    n=max_x-min_x;
                make_different_lines(i, j, n, min_x, max_x, min_y, max_y, 1, 1);
            }
            else
            {
                n = floor((max_y-min_y)/(max_x-min_x));
                if (n==0)
                    n=max_y-min_y;
                make_different_lines(j, i, n, min_y, max_y, min_x, max_x, 1, 0);
            }
        }
       else
       {
           int i = max_x-1, j=min_y-1;
           if (max_x-min_x>=max_y-min_y)
           {
               n = ceil((max_x-min_x)/(max_y-min_y));
               if (n==0)
                   n=max_x-min_x;
               make_different_lines(i, j, n, min_x, max_x, min_y, max_y, 0, 1);
           }
           else
           {
               n = floor((max_y-min_y)/(max_x-min_x));
               if (n==0)
                   n=max_y-min_y;
               make_different_lines(j, i, n, min_y, max_y, min_x, max_x, 0, 1);
               
           }
        }
}
Vector::Vector(int resolution, int x1, int y1, int x2, int y2)
{
    set_resolution(resolution);
    _matrix = new int * [_resolution];
    for (int i = 0; i<_resolution; i++)
    {
        _matrix[i]= new int [_resolution];
    }
    for (int i = 0; i<_resolution; i++)
    {
       for (int j = 0; j<_resolution; j++)
       {
           if ((i+1==y1&&j+1==x1)||(i+1==y2&&j+1==x2))
               _matrix[i][j] = 1;
           else _matrix[i][j] = 0;

       }
    }
    if (_matrix!=NULL)
    {
        if ((min(x1, x2)==x1&&min(y1, y2)==y1)||(min(x1, x2)==x2&&min(y1, y2)==y2))
            make_line(min(x1, x2), max(x1, x2), min(y1, y2), max(y1, y2), 1);
        else make_line(min(x1, x2), max(x1, x2), min(y1, y2), max(y1, y2), 0);
    }
    
}
void Vector:: set_resolution(int value)
{
    _resolution=value;
}
int Vector:: get_resolution() const
{
    return _resolution;
}
Vector::Vector(const Vector& a)
{
    _resolution=a._resolution;
    _matrix = new int * [_resolution];
    for (int i = 0; i<_resolution; i++)
    {
        _matrix[i]= new int [_resolution];
    }
    for (int i = 0; i<_resolution; i++)
    {
       for (int j = 0; j<_resolution; j++)
       {
           _matrix[i][j]=a._matrix[i][j];
       }
        
    }
    
}
Vector::~Vector()
{
    for (int i = 0; i<_resolution; i++)
    {
       delete _matrix[i];
    }
    delete [] _matrix;
}
Vector& Vector:: operator+(const Vector& obj)
{
    if (_resolution!=obj._resolution) throw EUnpossibal();
    for (int i = 0; i<_resolution; i++)
    {
       for (int j = 0; j<_resolution; j++)
       {
           if (_matrix[i][j]==0&&obj._matrix[i][j]==0)
               _matrix[i][j]=0;
           else _matrix[i][j]=1;
       }
    }
    return *this;
}
Vector& Vector:: operator*(const Vector& obj)
{
    if (_resolution!=obj._resolution) throw EUnpossibal();
    for (int i = 0; i<_resolution; i++)
    {
       for (int j = 0; j<_resolution; j++)
       {
           if (_matrix[i][j]==1&&obj._matrix[i][j]==1)
               _matrix[i][j]=1;
           else _matrix[i][j]=0;
       }
    }
    return *this;
}
Vector& Vector:: operator !()
{
    for (int i =0; i<_resolution; i++)
    {
        for (int j=0; j<_resolution; j++)
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
    for (int i =0; i<_resolution; i++)
    {
        for (int j=0; j<_resolution; j++)
        {
            if (_matrix[i][j]==1) counter++;
        }
    }
    return counter/_resolution*_resolution;
}
ostream& operator << (ostream& s, const Vector& obj)
{
//    for (int i = 0; i<obj._horizontal; i++)
//    {
//       for (int j = 0; j<obj._vertical; j++)
//       {
//           cout << obj._matrix[i][j];
//       }
//        cout<<endl;
//    }
   for (int i =obj._resolution-1; i>=0; i--)
    {
        for (int j =0; j<obj._resolution; j++)
            s << obj._matrix[i][j];
        s << endl;
    }
    return s;
}
