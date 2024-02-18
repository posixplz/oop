#include <array>
#include <iostream>
#include "test.hpp"
#define P(x) cout << x << endl;

using namespace std;

double rastojanje(Test&, Test&);

int main(void) {
	Test t1 (1.0, 2.0);
	Test t2 (3.0, 4.0);

	cout << rastojanje(t1, t2) << endl;
	return 0;
}
