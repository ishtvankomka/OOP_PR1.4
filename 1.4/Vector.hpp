#pragma once
#include <string>
#include <iostream>

using namespace std;

class Vector
{
private:
    int size = 0;
    int* array = new int[size];
public:
    //Vector() { size = 0; array = new int[size]; };
    friend void Read(Vector& vector1, Vector& vector2);
    friend void Display(Vector& vector1, Vector& vector2);
    friend void sum(Vector& vector1, Vector& vector2);
    friend void substraction(Vector& vector1, Vector& vector2);
    friend void multiplication(Vector& vector1, Vector& vector2, int m);
    friend void division(Vector& vector1, Vector& vector2, int d);
    bool Init(int s);
    void set_size(int value) { size = value; };
    void set_array();
    int get_size() { return size; };
    int get_array(int value);
    string toString(int);
    double convert(int);
    double toNumber(string);
};
