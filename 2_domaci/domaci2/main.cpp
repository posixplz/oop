#include <iostream>
#include "DomaciNiz.hpp"

int main(void)
{
	int N = 10;
	DomaciNiz niz(N);
	niz.Random();
	niz.Print();

	// Domaci 2
	// Dodatak
	std::cout << "\nSortiran niz:\n";
	niz.sort();
	niz.Print();
}
