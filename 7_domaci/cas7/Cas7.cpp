// Cas7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "vector.h"
int main()
{
    vector a(1, 2, 3);
    vector b(4, 5, 6);
    vector c;
    c = a + b;
    c.ispis();
    vector d;
    d = oduzimanje(a, b);
    d.ispis();
    std::cout << "Hello World!\n";
}

