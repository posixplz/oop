#include <iostream>
#include "matrica.hpp"
#include "double_matrica.hpp"

using namespace std;

int main(void) {
	Matrica M1(3, 3), M2(3, 3);
	M1.Random();
	M2.Zeroes();
	M1.Ispis();
	M2.Ispis();
	Matrica M3;
	M3 = M1 + M2;
	M3.Ispis();

	cout << M1[0][0] << '\n';

	cout << "M1[0][0] = 123;" << '\n';
	M1[0][0] = 123;
	M1.Ispis();

	cout << "M3:\n";
	for (int i=0; i<9; i++) {
		M3[i/3][i%3] = i+1;
	}
	M3.Ispis();

	cout << "M1.jedinicna();\n";
	M1.jedinicna();
	M1.Ispis();
	
	cout << "M1[0][1] = 2;\n";
	M1[0][1] = 2;
	M1.Ispis();

	try {
		cout << "M2:\n";
		M2.Ispis();
	
		cout << "M2 = M3 * M1; M2.Ispis();\n";
		M2 = M3 * M1;
		M2.Ispis();

		cout << "M3.rmRed(2);\n";
		M3.rmRed(2);
		M3.Ispis();

		cout << "M3.rmKol(1);\n";
		M3.rmKol(1);
		M3.Ispis();

		Matrica m4;

		cout << "m4 = rmKol(rmRed(M2, 2), 2);\n";
		m4 = c_rmKol(c_rmRed(M2, 2), 2);
		cout << "m4.Ispis();\n";
		m4.Ispis();

		cout << "M2.Ispis();\n";
		M2.Ispis();

		cout << "M2.Random();\n";
		M2.Random();
		cout << "M2.Ispis();\n";
		M2.Ispis();
		M2.print_mathematica_format();

		cout << "det(M2);\n";
		cout << '\t' << det(M2) << '\n';

		//// ovo bi bila greska, odradio bi catch ispod
		//// matrica za det() nije kvadratna
		// cout << "det(c_rmRed(M2, 0));\n";
		// det(c_rmRed(M2, 0));

		cout << "M2.rmRed(0); M2.Ispis();\n";
		M2.rmRed(0);
		M2.Ispis();
		cout << "M2.transp(); M2.Ispis();\n";
		M2.transp();
		M2.Ispis();

		cout << "M1.Random();\nM1.Ispis();\n";
		M1.Random();
		M1.Ispis();
		M1.print_mathematica_format();

		cout << "det(M1);\n";
		cout << '\t' << det(M1) << '\n';

		cout << "Matrica M5(kofaktorMatrica(M1));\nM5.Ispis();\n";
		Matrica M5(kofaktorMatrica(M1));
		M5.Ispis();
		M5.print_mathematica_format();

		cout << "DoubleMatrica M6(inv(M1)); M6.Ispis();\n";
		DoubleMatrica M6(inv(M1));
		M6.Ispis();
	} catch (const char* s) {
		cout << s << endl;
	}
	return 0;
}
