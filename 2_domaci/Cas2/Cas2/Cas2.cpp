// Cas2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <math.h>
using std::string;
//using namespace std;

struct cestica
{
    double m;
    double q;
    double x, y, z;
    double vx, vy, vz;    
};


//Napisati strutkuru cestica koja ima atribute : koordinate (3D), brzinu (3D), masu, naelektrisanje, ...
// U glavnom programu napraviti dve cestice, elektron i proton i dodeliti im bilo koje koordinate i brzine


//napisati f-ju za racunanje rastojanja izmedju dve cestice
//napisati f-ju za racunanje sile 

double rastojanje(cestica A, cestica B)
{
    double l = sqrt(pow(A.x - B.x, 2) + pow(A.y - B.y, 2) + pow(A.z - B.z, 2));
    return l;
}

double F(cestica A, cestica B)
{
    double l = rastojanje(A, B);
    double f = 1.0 / (4 * 3.14 * 8.85e-12) * A.q * B.q / (l * l);
    return f;
}
int main()
{
    cestica e, p;

    e.m = 9.109e-31; //kg
    e.q = -1.602e-19; //c
    
    e.x = rand();
    e.y = rand();
    e.z = rand();

    e.vx = rand();
    e.vy = rand();
    e.vz = rand();

    p.m = 1.673e-27; //kg
    p.q = 1.602e-19; //c

    p.x = rand();
    p.y = rand();
    p.z = rand();

    p.vx = rand();
    p.vy = rand();
    p.vz = rand();


    // test
 /*   e.x = 0;
    e.y = 0;
    e.z = 0;
    p.x = 1;
    p.y = 0;
    p.z = 0;*/


    std::cout << "F = "<< F(e, p) << "N\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
