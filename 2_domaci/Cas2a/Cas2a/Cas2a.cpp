// Cas2a.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

void MyFunction(int &a)
{
    a = 5;
    std::cout << "Adresa a: "<< &a << std::endl;
}

int main()
{
    //reference
    std::string food = "cevap";
    std::cout << &food << std::endl;

    int b = 1;
    MyFunction(b);
    std::cout << "Adresa b: " << &b << std::endl;
    std::cout << "b = " << b << std::endl;

    //pokazivaci

    std::string food2 = "Pizza";  // A food variable of type string
    std::string* ptr = &food2;    // A pointer variable, with the name ptr, that stores the address of food

    // Output the value of food (Pizza)
    std::cout << food2 << "\n";

    // Output the memory address of food (0x6dfed4)
    std::cout << &food2 << "\n";

    // Output the memory address of food with the pointer (0x6dfed4)
    std::cout << ptr << "\n";
    std::cout << *ptr << "\n";

    //
    int N = 0;
    std::cout << "unesi broj elemenata niza";
    std::cin >> N;
    
    int* niz = new int[N];

    delete[]niz;
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
