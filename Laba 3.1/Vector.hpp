

#ifndef Vector_hpp
#define Vector_hpp
#include "ESetErrors.hpp"
#include <stdio.h>
#include <cmath>
#include <vector>

template<typename T>
class Vector
{
private:
//    T** _matrix;
    int _resolution;
    vector < vector <T> > _matrix;
    int min (int a, int b);
    int max (int a, int b);
    void make_line(int min_x, int max_x, int min_y, int max_y, int flag_1,int flag_2);
public:
    auto begin() { return _matrix.begin(); }
    auto end() { return _matrix.end(); }
    auto rbegin() { return _matrix.rbegin(); }
    auto rend() { return _matrix.rend(); }
    auto cbegin() const { return _matrix.cbegin(); }
    auto cend() const { return _matrix.cend(); }
    Vector(int resolution=0);
    ~Vector();
    int get_resolution() const;
    void set_resolution(int value);
    void set_line(int x1, int y1, int x2, int y2);
    Vector(const Vector& a);
    T operator ()(int x, int y);
    void operator ()(int x, int y, const T value);
    Vector& operator *(Vector& obg);
    Vector& operator +(const Vector& obg);
    Vector& operator *(T value);
    Vector& operator +(T value);
    friend Vector& operator *(const T value, Vector& obj);
    friend Vector& operator +(const T value, Vector& obj);
    Vector& operator !();
    double coefficient_of_fullness();
    friend ostream& operator << (ostream& s, Vector& obj)
    {
        for (auto iter = obj.rbegin(); iter != obj.rend(); ++iter)
        {
            for(auto it = iter->begin(); it != iter->end(); ++it)
            {
                s << (*it);
            }
            s << endl;
        }
        
//       for (int i = obj.get_resolution() - 1; i >= 0; i--)
//        {
//            for (int j = 0; j < obj.get_resolution(); j++)
//            {
//                if (obj._matrix[i][j] == (T)0)
//                    s << " ";
//                else s << "1";
//            }
//            s << endl;
//        }
        return s;
    };

};

#endif /* Vector_hpp */
