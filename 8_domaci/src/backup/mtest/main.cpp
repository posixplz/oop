#include "matrica.hpp"

int main() {

	Matrica<int> m1(3);
	m1.fill(1);
	m1.print();

	Matrica<int> m2(3);
	m2.random(0, 9);
	m2.print();
	
	Matrica<int> m3;
	m3 = m2 + m1;
	m3.print();

	Matrica<int> m4(m3);
	m4.print();
	return 0;
}
