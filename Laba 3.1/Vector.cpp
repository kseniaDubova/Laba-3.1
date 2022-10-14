
#include "Vector.hpp"

int Vector:: max (int a, int b)
{ return (a>b) ? a: b;}
int Vector:: min (int a, int b)
{ return (a<b) ? a: b;}
void Vector:: make_line(int min_x, int max_x, int min_y, int max_y,int flag_1,int flag_2)
{
    int n;
    switch (flag_1)
    {
        case 1:
            switch (flag_2)
            {
                case 1:
                {
                    n = ceil((max_x-min_x)/(max_y-min_y));
                    if (n==0)
                        n=max_x-min_x;
                    int i = min_x-1, j=min_y-1;
                    while (i<max_x-1)
                    {
                        int count =1;
                        while (count<=n)
                       {
                            _matrix[j][i]=1;
                            count++;
                            i++;
                           
                       }
                        j++;
                        if (j==max_y-1)
                            j--;
                        count=0;
                    }
                    break;
                }
                    
                case 0:
                {
                    int i = min_x-1, j=min_y-1;
                    n = floor((max_y-min_y)/(max_x-min_x));
                    if (n==0)
                        n=max_y-min_y;
                    while (j<max_y-1)
                    {
                        int count =1;
                        while (count<=n)
                       {
                            _matrix[j][i]=1;
                            count++;
                           if (j!=max_y-1)
                               j++;
                           
                       }
                        i++;
                        if (i==max_x-1)
                            i--;
                        count=0;
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
                    int i = max_x-1, j=min_y-1;
                    n = ceil((max_x-min_x)/(max_y-min_y));
                    if (n==0)
                        n=max_x-min_x;
                    while (i>min_x-1)
                    {
                        int count =1;
                        while (count<=n)
                       {
                            _matrix[j][i]=1;
                            count++;
                            i--;
                           if (i==max_x-1)
                               i++;
                           
                       }
                        j++;
                        if (j==max_y-1)
                            j--;
                        count=0;
                    }
                    break;
                }
                case 0:
                {
                    int i = max_x-1, j=min_y-1;
                    n = floor((max_y-min_y)/(max_x-min_x));
                    if (n==0)
                        n=max_y-min_y;
                    while (j<max_y-1)
                    {
                        int count =1;
                        while (count<=n)
                       {
                            _matrix[j][i]=1;
                            count++;
                            j++;

                       }
                        i--;
                        if (i==max_x-1)
                            i++;
                        count=0;
                    }
                    break;
                }
            }
            break;
    }
}
Vector::Vector(int resolution, int x1, int y1, int x2, int y2)
{
    set_resolution(resolution);
    _matrix = new bool * [_resolution];
    for (int i = 0; i<_resolution; i++)
    {
        _matrix[i]= new bool [_resolution];
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
        int flag_1=0, flag_2=0;
        if ((min(x1, x2)==x1&&min(y1, y2)==y1)||(min(x1, x2)==x2&&min(y1, y2)==y2))
            flag_1=1;
        if (max(x1, x2)-min(x1, x2)>max(y1, y2)-min(y1, y2))
            flag_2=1;
        make_line(min(x1, x2), max(x1, x2), min(y1, y2), max(y1, y2), flag_1, flag_2);
        
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
    _matrix = new bool * [_resolution];
    for (int i = 0; i<_resolution; i++)
    {
        _matrix[i]= new bool [_resolution];
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
           _matrix[i][j]=_matrix[i][j]||obj._matrix[i][j];
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
           _matrix[i][j]=_matrix[i][j]&&obj._matrix[i][j];
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

Vector& Vector:: operator *(bool value)
{
    for (int i = 0; i<_resolution; i++)
    {
       for (int j = 0; j<_resolution; j++)
       {
           _matrix[i][j]=_matrix[i][j]&&value;
       }
    }
    return *this;
}
Vector& Vector:: operator +(bool value)
{
    for (int i = 0; i<_resolution; i++)
    {
       for (int j = 0; j<_resolution; j++)
       {
           _matrix[i][j]=_matrix[i][j]||value;
       }
    }
    return *this;
}

double Vector:: coefficient_of_fullness()
{
    double counter = 0;
    for (int i =0; i<_resolution; i++)
    {
        for (int j=0; j<_resolution; j++)
        {
            if (_matrix[i][j]==1) counter++;
        }
    }

    return counter/(_resolution*_resolution);
}
ostream& operator << (ostream& s, const Vector& obj)
{
   for (int i =obj._resolution-1; i>=0; i--)
    {
        for (int j =0; j<obj._resolution; j++)
        {
            if (obj._matrix[i][j]==0)
                s << " ";
            else s << obj._matrix[i][j];
        }
        s << endl;
    }
    return s;
}
bool Vector:: operator ()(int x, int y)
{
    if (x<=0||y<=0||x>_resolution||y>_resolution) throw EUncorrectIndex();
    return _matrix[x-1][y-1];
}
void Vector:: operator ()(int x, int y, bool value)
{
    if (x<=0||y<=0||x>_resolution||y>_resolution) throw EUncorrectIndex();
    _matrix[x-1][y-1]=value;
}
Vector& operator *(const bool value, Vector& obj)
{
    return obj*value;
}

Vector& operator +(const bool value, Vector& obj)
{
    return obj+value;
}
