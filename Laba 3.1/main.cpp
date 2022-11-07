
#include "Vector.hpp"
#include <iostream>
#include <iomanip>
using namespace std;

void clear_monitor()
{
    for (int i=0; i<31; i++)
    {
        cout << endl;
    }
}
void test(int resolution, int& x, int& y)
{
    cout << "x = ";
    cin >> x;
    cout << "y = ";
    cin >> y;
    while (x<=0||x>resolution||y<=0||y>resolution)
    {
        cout << "Incorrect value" << endl;
        cout << "x = ";
        cin >> x;
        cout << "y = ";
        cin >> y;
    }
}
Vector creating_binary_lines()
{
    cout << "Creating binary lines" << endl;
    cout << "What is the image resolution? (n*n)" << endl;
    cout << "Resolution (n*n): n = ";
    int resolution;
    cin >> resolution;
    while (resolution <= 0)
    {
        cout << "Incorrect value" << endl;
        cout << "Resolution (n*n): n = ";
        cin >> resolution;
    }

    int x1,y1,x2,y2;
    cout << "Enter the coordinates of the beginning of the line (x,y)" << endl;
    cout << "Values must be greater than zero" << endl;
    test(resolution, x1, y1);
    cout << "Enter the coordinates of the ending of the line (x,y)" << endl;
    cout << "Values must be greater than zero" << endl;
    test(resolution, x2, y2);
    clear_monitor();
    Vector obj(resolution);
    obj.set_line(x1,y1,x2,y2);
    return obj;
}
int muny(Vector& obj)
{
    cout << "What are you want to do? To press.." << endl;
    cout << "1 - summarize"<< endl;
    cout << "2 - summarize with bool"<< endl;
    cout << "3 - multiply"<< endl;
    cout << "4 - multiply with bool"<< endl;
    cout << "5 - invert image" << endl;
    cout << "6 - image fullness calculation" << endl;
    cout << "7 - сhange one element" << endl;
    cout << "8 - show one element" << endl;
    cout << "9 - print image" << endl;
    cout << "10 - go out" << endl;
    cout << "Operation №";
    int n;
    cin >> n;
    while (n>10||n<=0)
    {
        cout << "Incorrect value" << endl << "Operation №";
        cin >> n;
    }
    clear_monitor();
    return n;
}
void sum(Vector& obj)
{
    cout << "Summarize" << endl;
    Vector tmp = creating_binary_lines();
    getchar();
    clear_monitor();
    obj = obj + tmp;
    cout << obj;
}
void sum_bool(Vector& obj)
{
    cout << "Summarize with bool" << endl;
    cout << "Enter boolean value (1/0/true/false)" << endl;
    bool value;
    cout << "Boolean value = ";
    cin >> value;
    obj=obj+value;
    cout << obj;
    getchar();
}
void mul(Vector& obj)
{
    cout << "Multiply" << endl;
    Vector tmp = creating_binary_lines();
    getchar();
    clear_monitor();
    obj = obj * tmp;
    cout << obj;
}
void mul_bool(Vector& obj)
{
    cout << "Multiply with bool" << endl;
    cout << "Enter boolean value (1/0/true/false)" << endl;
    bool value;
    cout << "Boolean value = ";
    cin >> value;
    obj=obj*value;
    cout << obj;
    getchar();
}
void invert(Vector& obj)
{
    cout << "Invert image" << endl;
    cout << !obj;
    getchar();
    
}
void fullness(Vector& obj)
{
    cout << "Image fullness = ";
    cout << setprecision(4) << obj.coefficient_of_fullness()<< endl;
    getchar();
}
void change_one(Vector& obj)
{
    cout << "Change one element" << endl;
    cout << "Enter the coordinates (x,y)" << endl;
    int x,y;
    test(obj.get_resolution(), x, y);
    cout << "Enter boolean value (1/0/true/false)" << endl;
    bool value;
    cout << "Boolean value = ";
    cin >> value;
    obj(x,y,value);
    cout << obj;
    getchar();
}
void show_one(Vector& obj)
{
    cout << "Change one element" << endl;
    cout << "Enter the coordinates (x,y)" << endl;
    int x,y;
    test(obj.get_resolution(), x, y);
    cout << "(" << x << "," << y << ")" << obj(x,y);
    getchar();
}
void print_obj(Vector& obj)
{
    cout << obj;
    getchar();
}
int main()
{
    void (*operatoin[9])(Vector& obj) = {sum, sum_bool, mul, mul_bool, invert, fullness, change_one, show_one, print_obj};
    Vector obj = creating_binary_lines();
    cout << obj;
    int n=muny(obj);
    getchar();
    while (n<10)
    {
        try {
            operatoin[n-1](obj);
        } catch (ESetErrors& err) {
            err.print_error();
        }
        getchar();
        clear_monitor();
        cout << "What's next?" << endl;
        n=muny(obj);
    }

    return 0;
}
