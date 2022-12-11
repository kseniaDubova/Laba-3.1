
#include "Vector.hpp"
#include <iostream>
#include <iomanip>
//#include <string.h>
using namespace std;


void clear_monitor()
{
    for (int i = 0; i < 31; i++)
    {
        cout << endl;
    }
}


int check()
{
    int number = -1;
    while (number < 0)
    {
        while (!(cin >> number) || (cin.peek() != '\n'))
        {
            cin.clear();
            while (cin.get() != '\n');
            cout << "Incorrect value" << endl;
        }
       if (number < 0) cout << "Incorrect value" << endl;
    }
    return number;
}


void test(int resolution, int& x, int& y)
{
    cout << "x = ";
    x = check();
    cout << "y = ";
    y = check();
    while (x < 0 || x > resolution || y < 0 || y > resolution)
    {
        cout << "Incorrect value" << endl;
        cout << "x = ";
        x = check();
        cout << "y = ";
        y = check();
    }
}


template<typename T>
Vector<T> creating_binary_lines()
{
    cout << "Creating binary lines" << endl;
    cout << "What is the image resolution? (n*n)" << endl;
    cout << "Resolution (n*n): n = ";
    int resolution = check();
    while (resolution <= 0)
    {
        cout << "Incorrect value" << endl;
        cout << "Resolution (n*n): n = ";
        cin >> resolution;
    }

    int x1,y1,x2,y2;
    cout << "Enter the coordinates of the beginning of the line (x,y)" << endl;
//    cout << "Values must be greater than zero" << endl;
    test(resolution, x1, y1);
    cout << "Enter the coordinates of the ending of the line (x,y)" << endl;
//    cout << "Values must be greater than zero" << endl;
    test(resolution, x2, y2);
    clear_monitor();
    Vector<T> obj(resolution);
    obj.set_line(x1,y1,x2,y2);
    return obj;
}


template<typename T>
int muny(Vector<T>& obj)
{
    cout << "What are you want to do? To press.." << endl;
    cout << "1 - summarize"<< endl;
    cout << "2 - summarize with value"<< endl;
    cout << "3 - multiply"<< endl;
    cout << "4 - multiply with value"<< endl;
    cout << "5 - invert image" << endl;
    cout << "6 - image fullness calculation" << endl;
    cout << "7 - сhange one element" << endl;
    cout << "8 - show one element" << endl;
    cout << "9 - print image" << endl;
    cout << "10 - go out" << endl;
    cout << "Operation №";
    int n = check();
    while (n > 10 || n <= 0)
    {
        cout << "Incorrect value" << endl << "Operation №";
        cin >> n;
    }
    clear_monitor();
    return n;
}


template<typename T>
void sum(Vector<T>& obj)
{
    cout << "Summarize" << endl;
    Vector<T> tmp = creating_binary_lines<T>();
    getchar();
    clear_monitor();
    obj = obj + tmp;
    cout << obj;
}


template<typename T>
void sum_bool(Vector<T>& obj)
{
    cout << "Summarize with" << endl;
    cout << "Enter value (1/0)" << endl;
    cout << "Value = ";
    T value = check();
    while(value != 1 && value != 0)
    {
        cout << "Incorrect value" << endl;
        value = check();
    }
    obj = obj + value;
    cout << obj;
    getchar();
}


template<typename T>
void mul(Vector<T>& obj)
{
    cout << "Multiply" << endl;
    Vector<T> tmp = creating_binary_lines<T>();
    getchar();
    clear_monitor();
    obj = obj * tmp;
    cout << obj;
}


template<typename T>
void mul_bool(Vector<T>& obj)
{
    cout << "Multiply" << endl;
    cout << "Enter value (1/0)" << endl;
    T value = check();
    while(value != 1 && value != 0)
    {
        cout << "Incorrect value" << endl;
        value = check();
    }
    obj = obj * value;
    cout << obj;
    getchar();
}


template<typename T>
void invert(Vector<T>& obj)
{
    cout << "Invert image" << endl;
    cout << !obj;
    getchar();
}


template<typename T>
void fullness(Vector<T>& obj)
{
    cout << "Image fullness = ";
    cout << setprecision(4) << obj.coefficient_of_fullness() << endl;
    getchar();
}


template<typename T>
void change_one(Vector<T>& obj)
{
    cout << "Change one element" << endl;
    cout << "Enter the coordinates (x,y)" << endl;
    int x, y;
    test(obj.get_resolution(), x, y);
    cout << "Enter value (1/0)" << endl;
    T value = check();
    while(value != 1 && value != 0)
    {
        cout << "Incorrect value" << endl;
        value = check();
    }
    obj(x, y, value);
    cout << obj;
    getchar();
}


template<typename T>
void show_one(Vector<T>& obj)
{
    cout << "Change one element" << endl;
    cout << "Enter the coordinates (x,y)" << endl;
    int x, y;
    test(obj.get_resolution(), x, y);
    cout << "(" << x << "," << y << ")" << obj(x, y);
    getchar();
}


template<typename T>
void print_obj(Vector<T>& obj)
{
    cout << obj;
    getchar();
}


template<typename T>
void application()
{
    void (*operatoin[9])(Vector<T>& obj) = {sum, sum_bool, mul, mul_bool, invert, fullness, change_one, show_one, print_obj};
    Vector<T> obj = creating_binary_lines<T>();
    cout << obj;
    int n = muny(obj);
    getchar();
    while (n < 10)
    {
        try {
            operatoin[n - 1](obj);
        } catch (ESetErrors& err) {
            err.print_error();
        }
        getchar();
        clear_monitor();
        cout << "What's next?" << endl;
        n = muny(obj);
    }
}


int main()
{
    cout << "Select data type:" << endl;
    cout << "1 - float" << endl;
    cout << "2 - short" << endl;
    cout << "3 - char" << endl;
    cout << "4 - bool" << endl;
    cout << "type: ";
    int type;
    cin >> type;
    while (type <= 0 || type > 4)
    {
        cout << "Incorrect value" << endl;
        cout << "type: ";
        cin >> type;
    }
    getchar();
    clear_monitor();
    switch (type) {
        case 1:
            application<float>();
            break;
        case 2:
            application<short>();
            break;
        case 3:
            application<char>();
            break;
        case 4:
            application<bool>();
            break;
    }
    return 0;
}
