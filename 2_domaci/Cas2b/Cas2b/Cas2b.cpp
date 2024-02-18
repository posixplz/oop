// Cas2b.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
struct Niz
{
    int N;
    int* niz;
};
void sort(Niz A)
{
    int n = A.N;
    int buffer;
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
        {
            if (A.niz[i] > A.niz[j])
            {
                buffer = A.niz[i];
                A.niz[i] = A.niz[j];
                A.niz[j] = buffer;
            }
        }
}
int main()
{
    Niz A;
    A.N = 100;
    A.niz = new int[A.N];
    for (int i = 0; i < A.N; i++)
    {
        A.niz[i] = rand();
    }

    //sort

    delete[]A.niz;
    std::cout << "Hello World!\n";
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
