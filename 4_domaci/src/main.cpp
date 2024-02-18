#include <iostream>
#include <stdio.h>
#include "krug.hpp"

#define P(x)	cout << x << endl;

using namespace std;

enum { x=0, y=1 };

void printK(Krug&);
void printK(Krug&, Krug&);

int main(void) {
	cout << "\t{xx.x, yy.y},\tR,\tO,\tP\n"
		<< "komanda;\n\n"
		<< "----------------------------------------------"
		<< endl << endl;

	Krug k1 (10.0, -12.0, 5.0);
	Krug k2 (3.0, 5.0, 2.0);
	printK(k1, k2);
	
	k1.centar.translacija(-10.0, 0.0);
	P("k1.centar.translacija(-10.0, 0.0);")
	k2.centar.translacija(-3.0, 0.0);
	P("k2.centar.translacija(-3.0, 0.0);")
	printK(k1, k2);

	k1.centar.translacija(0.0, 12.0);
	P("k1.centar.translacija(-10.0, 0.0);")
	k2.centar.translacija(0.0, -5.0);
	P("k2.centar.translacija(-3.0, 0.0);")
	printK(k1, k2);

	k2.centar.translacija(0.0, 3.0);
	P("k2.centar.translacija(0.0, 3.0);");
	printK(k1, k2);

	k2.centar.translacija(0.0, 4.0);
	P("k2.centar.translacija(0.0, 4.0);");
	printK(k1, k2);

	k2.centar.translacija(0.0, 0.1);
	P("k2.centar.translacija(0.0, 0.1);");
	printK(k1, k2);
	
	k2.setR(3.0);
	P("k2.setR(3.0);")
	printK(k1,k2);
	
	k1.centar.set(x, 4.0);
	P("k1.centar.set(x, 4.0);");
	printK(k1,k2);

	return 0;
}

void printK(Krug& k) {
	printf("\t{%.1f, %.1f},\t%.1f\t%.1f\t%.1f\n",
		k.centar.get(x), k.centar.get(y),
		k.getR(), k.obim(), k.povrsina());
	return;
}

void printK(Krug& k1, Krug& k2) {
	printK(k1);
	printK(k2);
	cout << "\tr(k1, k2)\t\t= "
		<< rastojanje(k1, k2) << endl
		<< "\tr(k1.centar, k2.centar)\t= "
		<< rastojanje(k1.centar, k2.centar)
		<< endl << endl;
	return;
}
