//
//  main.cpp
//  Laba 3.1
//
//  Created by Ксения Дубова on 26.09.2022.
//
#include "Vector.hpp"
#include <iostream>
using namespace std;

void clear_monitor()
{
    for (int i=0; i<31; i++)
    {
        cout << endl;
    }
}
void test(int hor, int vert, int& x, int& y)
{
    cout << "x = ";
    cin >> x;
    cout << "y = ";
    cin >> y;
    while (x<0||x>hor||y<0||y>vert)
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
    cout << "What is the image resolution?" << endl;
    cout << "Horizontal: ";
    int horizontal;
    int vertical;
    cin >> horizontal;
    while (horizontal <= 0)
    {
        cout << "Incorrect value" << endl;
        cout << "Horizontal: ";
        cin >> horizontal;
    }
    cout << "Vertical: ";
    cin >> vertical;
    while (vertical <= 0)
    {
        cout << "Incorrect value" << endl;
        cout << "Vertical: ";
        cin >> vertical;
    }
    int x1,y1,x2,y2;
    cout << "Enter the coordinates of the beginning of the line (x,y)" << endl;
    test(horizontal, vertical, x1, y1);
    cout << "Enter the coordinates of the ending of the line (x,y)" << endl;
    test(horizontal, vertical, x2, y2);
    clear_monitor();
    return Vector(horizontal,vertical,x1,y1,x2,y2);
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
    cout << "7 - go out" << endl;
    cout << "Operation №";
    int n;
    cin >> n;
    while (n>7||n<=0)
    {
        cout << "Incorrect value" << endl << "Operation №";
        cin >> n;
    }
    return n;
}
int main()
{
    try
    {
        Vector obj = creating_binary_lines();
        getchar();
        clear_monitor();
//        int n = muny(obj);
    } catch (ESetErrors& err)
    {
        err.print_error();
        getchar();
        clear_monitor();
        
        
    }
    
    return 0;
}
