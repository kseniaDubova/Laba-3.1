
#include "Vector.hpp"


template<typename T>
int Vector<T>:: max (int a, int b)
{ return (a > b) ? a: b;}


template<typename T>
int Vector<T>:: min (int a, int b)
{ return (a < b) ? a: b;}


template<typename T>
void Vector<T>:: make_line(int min_x, int max_x, int min_y, int max_y,int flag_1,int flag_2)
{
    switch (flag_1)
    {
        case 1:
            switch (flag_2)
            {
                case 1:
                {
                    int deltax = abs(max_x - min_x);
                    int deltay = abs(max_y - min_y);
                    int error = 0;
                    int deltaerr = (deltay + 1);
                    int y = min_y;
                    int diry = max_y - min_y;
                    if (diry > 0)
                        diry = 1;
                    if (diry < 0)
                        diry = -1;
                    for (int x = min_x; x <= max_x; x++)
                    {
                        _matrix[y][x] = (T)1;
                        error = error + deltaerr;
                        if (error >= (deltax + 1))
                        {
                            y = y + diry;
                            error = error - (deltax + 1);
                        }
                    }
                    break;
                }
                case 0:
                {
                    int deltax = abs(max_x - min_x);
                    int deltay = abs(max_y - min_y);
                    int error = 0;
                    int deltaerr = (deltax + 1);
                    int x = min_x;
                    int dirx = max_x - min_x;
                    if (dirx > 0)
                        dirx = 1;
                    if (dirx < 0)
                        dirx = -1;
                    for (int y = min_y; y <= max_y; y++)
                    {
                        _matrix[y][x] = (T)1;
                        error = error + deltaerr;
                        if (error >= (deltay + 1))
                        {
                            x = x + dirx;
                            error = error - (deltay + 1);
                        }
                    }
                    break;
                }
            }
            break;
        case 0:
            switch (flag_2)
            {
                case 1:
                {
                    int deltax = abs(max_x - min_x);
                    int deltay = abs(max_y - min_y);
                    int error = 0;
                    int deltaerr = (deltay + 1);
                    int y = min_y;
                    int diry = max_y - min_y;
                    if (diry > 0)
                        diry = 1;
                    if (diry < 0)
                        diry = -1;
                    for (int x = max_x; x >= min_x; x--)
                    {
                        _matrix[y][x] = (T)1;
                        error = error + deltaerr;
                        if (error >= (deltax + 1))
                        {
                            y = y + diry;
                            error = error - (deltax + 1);
                        }
                    }
                    break;
                }
                case 0:
                {
                    int deltax = abs(max_x - min_x);
                    int deltay = abs(max_y - min_y);
                    int error = 0;
                    int deltaerr = (deltax + 1);
                    int x = min_x;
                    int dirx = max_x - min_x;
                    if (dirx > 0)
                        dirx = 1;
                    if (dirx < 0)
                        dirx = -1;
                    for (int y = max_y; y >= min_y; y--)
                    {
                        _matrix[y][x] = (T)1;
                        error = error + deltaerr;
                        if (error >= (deltay + 1))
                        {
                            x = x + dirx;
                            error = error - (deltay + 1);
                        }
                    }
                    break;
                }
            }
            break;
    }
}


template<typename T>
Vector<T>::Vector(int resolution)
{
    set_resolution(resolution);
    _matrix = new T * [_resolution];
    for (int i = 0; i < _resolution; i++)
    {
        _matrix[i]= new T [_resolution];
    }
}


template<typename T>
void Vector<T>:: set_line(int x1, int y1, int x2, int y2)
{
    if (_matrix == NULL) throw EUnpossibal();
    for (int i = 0; i < _resolution; i++)
    {
       for (int j = 0; j < _resolution; j++)
       {
            _matrix[i][j] = (T)0;
       }
    }
    int flag_1 = 0, flag_2 = 0;
    if ((min(x1, x2) == x1 && min(y1, y2) == y1)||(min(x1, x2) == x2 && min(y1, y2) == y2))
        flag_1 = 1;
    if (max(x1, x2) - min(x1, x2) > max(y1, y2) - min(y1, y2))
        flag_2 = 1;
    make_line(min(x1, x2), max(x1, x2), min(y1, y2), max(y1, y2), flag_1, flag_2);
}


template<typename T>
void Vector<T>:: set_resolution(int value)
{
    _resolution = value;
}


template<typename T>
int Vector<T>:: get_resolution() const
{
    return _resolution;
}


template<typename T>
Vector<T>::Vector(const Vector<T>& a)
{
    _resolution = a._resolution;
    _matrix = new T * [_resolution];
    for (int i = 0; i < _resolution; i++)
    {
        _matrix[i] = new T [_resolution];
    }
    for (int i = 0; i < _resolution; i++)
    {
       for (int j = 0; j < _resolution; j++)
       {
           _matrix[i][j] = a._matrix[i][j];
       }
    }
}


template<typename T>
Vector<T>::~Vector()
{
    for (int i = 0; i < _resolution; i++)
    {
       delete _matrix[i];
    }
    delete [] _matrix;
}


template<typename T>
Vector<T>& Vector<T>:: operator+(const Vector& obj)
{
    if (_resolution != obj._resolution) throw EUnpossibal();
    for (int i = 0; i < _resolution; i++)
    {
       for (int j = 0; j < _resolution; j++)
       {
           _matrix[i][j] = _matrix[i][j]||obj._matrix[i][j];
       }
    }
    return *this;
}


template<typename T>
Vector<T>& Vector<T>:: operator*(const Vector& obj)
{
    if (_resolution != obj._resolution) throw EUnpossibal();
    for (int i = 0; i < _resolution; i++)
    {
       for (int j = 0; j < _resolution; j++)
       {
           _matrix[i][j] = _matrix[i][j]&&obj._matrix[i][j];
       }
    }
    return *this;
}


template<typename T>
Vector<T>& Vector<T>:: operator !()
{
    for (int i = 0; i < _resolution; i++)
    {
        for (int j = 0; j < _resolution; j++)
        {
            if (_matrix[i][j] == (T)1)
                _matrix[i][j] = (T)0;
            else _matrix[i][j] = (T)1;
        }
    }
    return *this;
}


template<typename T>
Vector<T>& Vector<T>:: operator *(T value)
{
    for (int i = 0; i < _resolution; i++)
    {
       for (int j = 0; j < _resolution; j++)
       {
           _matrix[i][j] = _matrix[i][j]&&value;
       }
    }
    return *this;
}


template<typename T>
Vector<T>& Vector<T>:: operator +(T value)
{
    for (int i = 0; i < _resolution; i++)
    {
       for (int j = 0; j < _resolution; j++)
       {
           _matrix[i][j] = _matrix[i][j]||value;
       }
    }
    return *this;
}


template<typename T>
double Vector<T>:: coefficient_of_fullness()
{
    double counter = 0;
    for (int i = 0; i < _resolution; i++)
    {
        for (int j = 0; j < _resolution; j++)
        {
            if (_matrix[i][j] == (T)1)
                counter++;
        }
    }
    return counter / (_resolution*_resolution);
}


template<typename T>
T Vector<T>:: operator ()(int x, int y)
{
    if (x <= 0 || y <= 0 || x > _resolution || y > _resolution) throw EUncorrectIndex();
    return _matrix[x - 1][y - 1];
}


template<typename T>
void Vector<T>:: operator ()(int x, int y, T value)
{
    if (x <= 0 || y <= 0 || x > _resolution || y > _resolution) throw EUncorrectIndex();
    _matrix[x - 1][y - 1] = value;
}


template<typename T>
Vector<T>& operator *(const T value, Vector<T>& obj)
{
    return obj*value;
}


template<typename T>
Vector<T>& operator +(const T value, Vector<T>& obj)
{
    return obj + value;
}

template class Vector<float>;
template class Vector<short>;
template class Vector<char>;
template class Vector<bool>;
