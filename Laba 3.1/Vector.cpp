
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
void Vector:: make_different_lines(int i, int j, int n, int min_x, int max_x, int min_y, int max_y, bool flag)
{
    while (i<max_x-1)
    {
        int count =1;
        while (count<=n)
       {
           if (flag)
               _matrix[j][i]=1;
           else _matrix[i][j]=1;

//                cout << i<<j<<"  " << _matrix[i][j]<<endl;
            count++;
            i++;
           
       }
        j++;
        if (j==max_y-1)
            j--;
        count=0;
    }

}
void Vector:: make_line(int min_x, int max_x, int min_y, int max_y)
{
    if (max_x-min_x>max_y-min_y||max_x-min_x<max_y-min_y)
        {
            int n;
            int i = min_x-1, j=min_y-1;
            if (max_x-min_x>max_y-min_y)
            {
                n = ceil((max_x-min_x)/(max_y-min_y));
                make_different_lines(i, j, n, min_x, max_x, min_y, max_y, 1);
            }
            else
            {
                n = floor((max_y-min_y)/(max_x-min_x));
                make_different_lines(j, i, n, min_y, max_y, min_x, max_x, 0);
                
                
//                написать очищалку сверху 
                
                
//                while (j<max_y-1)
//                {
//                    int count =1;
//                    while (count<=n)
//                    {
//                        _matrix[j][i]=1;
//            //                cout << i<<j<<"  " << _matrix[i][j]<<endl;
//                        count++;
//                        j++;
//                    }
//                    i++;
//                    if (i==max_x-1)
//                        i--;
//                    count=0;
//                }
            }
            
            
        }
}
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
    if (_matrix!=NULL)
        make_line(min(x1, x2), max(x1, x2), min(y1, y2), max(y1, y2));
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
    return counter/_vertical*_horizontal;
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
   for (int i =obj._horizontal-1; i>=0; i--)
    {
        for (int j =0; j<obj._vertical; j++)
            s << obj._matrix[i][j];
        s << endl;
    }
    return s;
}
