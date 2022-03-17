#include "Vector.hpp"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <sstream>

using namespace std;

void Vector::set_array()
{
    int n = get_size();
    for (int i = 0; i < n; i++)
    {
        int r = rand() % 100 + 1;
        array[i] = r;
    }
}

int Vector::get_array(int value)
{
    return array[value];
}

bool Vector::Init(int s)
{
    if (s > 0)
    {
        return true;
    }
    else
        cout << "Wrong argument to init!" << endl;
        return false;
}

void Read(Vector& vector1, Vector& vector2)
{
    //get size of arrays from the user
    int s;
    do
    {
        cout << "Set the size: "; cin >> s;
    }
    while(!vector1.Init(s));
    //set the size and making arrays
    vector1.set_size(s);
    vector2.set_size(s);
    vector1.set_array();
    vector2.set_array();
    
    //show arrays for the user
    
    cout << "1st array: ";
    for(int i = 0; i < s; i++)
    {
        int a = vector1.get_array(i);
        cout << "[" << a << "] ";
    }
    cout << endl;
    
    cout << "2nd array: ";
    for(int i = 0; i < s; i++)
    {
        int a = vector2.get_array(i);
        cout << "[" << a << "] ";
    }
    cout << endl;
}

void Display(Vector& vector1, Vector& vector2)
{
    int botton;
    do
    {
        cout << "MENU:\n1 - '+'\n2 - '-'\n3 - '*'\n4 - '/'\n5 - EXIT" << endl;
        cin >> botton;
        switch(botton)
        {
            case 1:
                cout << "Result of + is ";
                sum(vector1, vector2);
                cout << endl;
                break;
                
            case 2:
                cout << "Result of - is ";
                substraction(vector1, vector2);
                cout << endl;
                break;
                
            case 3:
                int m;
                cout << "Set the multiplier: "; cin >> m;
                cout << "Result of * is ";
                multiplication(vector1, vector2, m);
                cout << endl;
                break;
                
            case 4:
                int d;
                cout << "Set the divider: "; cin >> d;
                cout << "Result of / is ";
                division(vector1, vector2, d);
                cout << endl;
                break;
            
            case 5:
                cout << "Program is terminated" << endl;
                break;
        }
    }
    while(botton != 5);
}

void sum(Vector& vector1, Vector& vector2)
{
    int s = vector1.get_size();
    for(int i = 0; i < s; i++)
    {
        int a = vector1.get_array(i);
        int b = vector2.get_array(i);
        int c = a + b;
        cout << "[" << c << "] ";
    }
}

void substraction(Vector& vector1, Vector& vector2)
{
    int s = vector1.get_size();
    for(int i = 0; i < s; i++)
    {
        int a = vector1.get_array(i);
        int b = vector2.get_array(i);
        int c = a - b;
        cout << "[" << c << "] ";
    }
}

void multiplication(Vector& vector1, Vector& vector2, int m)
{
    int s = vector1.get_size();
    cout << endl;
    cout << "1st array: ";
    for(int i = 0; i < s; i++)
    {
        int a = vector1.get_array(i);
        int b = a * m;
        cout << "[" << b << "] ";
    }
    cout << endl;
    cout << "2nd array: ";
    for(int i = 0; i < s; i++)
    {
        int a = vector2.get_array(i);
        int b = a * m;
        cout << "[" << b << "] ";
    }
}

//double b = (double) a; divider

void division(Vector& vector1, Vector& vector2, int d)
{
    int s = vector1.get_size();
    cout << endl;
    cout << "1st array: ";
    for(int i = 0; i < s; i++)
    {
        int a = vector1.get_array(i);
        double b = vector1.convert(a);
        double c = b / d;
        cout << "[" << c << "] ";
    }
    
    
    cout << endl;
    cout << "2nd array: ";
    for(int i = 0; i < s; i++)
    {
        int a = vector2.get_array(i);
        double b = vector2.convert(a);
        double c = b / d;
        cout << "[" << c << "] ";
    }
}

double Vector::convert(int a)
{
    return toNumber(toString(a));
}

string Vector::toString(int a)
{
    stringstream ss1;
    ss1 << a;
    string str1 = ss1.str();
    stringstream ss2;
    int b = 0;
    ss2 << b;
    string str2 = ss2.str();
    return str1 + "." + str2;
}

double Vector::toNumber(string str)
{
    double a;
    istringstream ( str ) >> a;
    return a;
}
