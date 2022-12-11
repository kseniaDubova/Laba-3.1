
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
//    auto iter = begin();
//    auto it = iter->begin();
    
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
//                        iter += y;
//                        it += x;
//                        *it = (T)1;
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
//                        iter += y;
//                        it += x;
//                        *it = (T)1;
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
//                        iter += y;
//                        it += x;
//                        *it = (T)1;
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
//                        iter += y;
//                        it += x;
//                        *it = (T)1;
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
    set_resolution(resolution + 1);
    vector < vector <T> > matrix (_resolution, vector <T> (_resolution));
    _matrix = matrix;
    
//    _matrix = new T * [_resolution];
//    for (int i = 0; i < _resolution; i++)
//    {
//        _matrix[i]= new T [_resolution];
//    }
}


template<typename T>
Vector<T>::~Vector()
{
    _matrix.clear();
}

template<typename T>
void Vector<T>:: set_line(int x1, int y1, int x2, int y2)
{
//    if (_matrix == NULL) throw EUnpossibal();
    for (auto iter = begin(); iter != end(); ++iter)
    {
        for(auto it = iter->begin(); it != iter->end(); ++it)
        {
            (*it) = (T)0;
        }
    }
//    for (int i = 0; i < _resolution; i++)
//    {
//       for (int j = 0; j < _resolution; j++)
//       {
//            _matrix[i][j] = (T)0;
//       }
//    }
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
Vector<T>::Vector(const Vector<T>& obj)
{
    _resolution = obj._resolution;
    _matrix.reserve(_resolution);
//    _matrix = new T * [_resolution];
//    for (int i = 0; i < _resolution; i++)
//    {
//        _matrix[i] = new T [_resolution];
//    }
    auto obj_iter = obj.cbegin();
    for (auto iter = begin(); iter != end(); ++iter)
    {
        auto obj_it = obj_iter->begin();
        for(auto it = iter->begin(); it != iter->end(); ++it)
        {
            (*it) = (*obj_it);
            ++obj_it;
        }
        ++obj_iter;
    }
//    for (int i = 0; i < _resolution; i++)
//    {
//       for (int j = 0; j < _resolution; j++)
//       {
//           _matrix[i][j] = a._matrix[i][j];
//       }
//    }
}


template<typename T>
Vector<T>& Vector<T>:: operator+(const Vector& obj)
{
    if (_resolution != obj._resolution) throw EUnpossibal();
    auto obj_iter = obj.cbegin();
    for (auto iter = begin(); iter != end(); ++iter)
    {
        auto obj_it = obj_iter->begin();
        for(auto it = iter->begin(); it != iter->end(); ++it)
        {
            (*it) = (*it)||(*obj_it);
            ++obj_it;
        }
        ++obj_iter;
    }
//    for (int i = 0; i < _resolution; i++)
//    {
//       for (int j = 0; j < _resolution; j++)
//       {
//           _matrix[i][j] = _matrix[i][j]||obj._matrix[i][j];
//       }
//    }
    return *this;
}


template<typename T>
Vector<T>& Vector<T>:: operator*(Vector& obj)
{
    if (_resolution != obj._resolution) throw EUnpossibal();
    auto obj_iter = obj.begin();
    for (auto iter = begin(); iter != end(); ++iter)
    {
        auto obj_it = obj_iter->begin();
        for(auto it = iter->begin(); it != iter->end(); ++it)
        {
            (*it) = (*it)&&(*obj_it);
            ++obj_it;
        }
        ++obj_iter;
    }
//    for (int i = 0; i < _resolution; i++)
//    {
//       for (int j = 0; j < _resolution; j++)
//       {
//           _matrix[i][j] = _matrix[i][j]&&obj._matrix[i][j];
//       }
//    }
    return *this;
}


template<typename T>
Vector<T>& Vector<T>:: operator !()
{
    for (auto iter = begin(); iter != end(); iter++)
    {
        for(auto it = iter->begin(); it != iter->end(); it++)
        {
            if ((*it) == (T)1)
                (*it) = (T)0;
            else (*it) = (T)1;
        }
    }
//    for (int i = 0; i < _resolution; i++)
//    {
//        for (int j = 0; j < _resolution; j++)
//        {
//            if (_matrix[i][j] == (T)1)
//                _matrix[i][j] = (T)0;
//            else _matrix[i][j] = (T)1;
//        }
//    }
    return *this;
}


template<typename T>
Vector<T>& Vector<T>:: operator *(T value)
{
    for (auto iter = begin(); iter != end(); ++iter)
    {
        for(auto it = iter->begin(); it != iter->end(); ++it)
        {
            (*it) = (*it)&&value;
        }
    }
//    for (int i = 0; i < _resolution; i++)
//    {
//       for (int j = 0; j < _resolution; j++)
//       {
//           _matrix[i][j] = _matrix[i][j]&&value;
//       }
//    }
    return *this;
}


template<typename T>
Vector<T>& Vector<T>:: operator +(T value)
{
    for (auto iter = begin(); iter != end(); ++iter)
    {
        for(auto it = iter->begin(); it != iter->end(); ++it)
        {
            (*it) = (*it)||value;
        }
    }
//    for (int i = 0; i < _resolution; i++)
//    {
//       for (int j = 0; j < _resolution; j++)
//       {
//           _matrix[i][j] = _matrix[i][j]||value;
//       }
//    }
    return *this;
}


template<typename T>
double Vector<T>:: coefficient_of_fullness()
{
    double counter = 0;
    for (auto iter = begin(); iter != end(); ++iter)
    {
        for(auto it = iter->begin(); it != iter->end(); ++it)
        {
            if ((*it) == (T)1)
                counter++;
        }
    }
//    for (int i = 0; i < _resolution; i++)
//    {
//        for (int j = 0; j < _resolution; j++)
//        {
//            if (_matrix[i][j] == (T)1)
//                counter++;
//        }
//    }
    return counter / (_resolution*_resolution);
}


template<typename T>
T Vector<T>:: operator ()(int x, int y)
{
    if (x < 0 || y < 0 || x > _resolution || y > _resolution) throw EUncorrectIndex();
    auto iter = cbegin();
    iter += y;
    auto it = iter->cbegin();
    it += x;
    return *it;
}


template<typename T>
void Vector<T>:: operator ()(int x, int y, const T value)
{
    if (x < 0 || y < 0 || x > _resolution || y > _resolution) throw EUncorrectIndex();
    auto iter = begin();
    iter += y;
    auto it = iter->begin();
    it += x;
    (*it) = value;
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
