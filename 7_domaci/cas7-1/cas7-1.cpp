// Cas7-1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "matrica.h"
int main()
{
    Matrica M1(3, 3), M2(3, 3);
    M1.Random();
    M2.Zeroes();
    M1.Ispis();
    M2.Ispis();
    Matrica M3;
    M3 = M1 + M2;
    M3.Ispis();


    std::cout << M1[0][0];
}

