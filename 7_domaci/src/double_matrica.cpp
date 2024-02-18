#include <iostream>
#include <new>
#include "matrica.hpp"
#include "double_matrica.hpp"

using namespace std;

DoubleMatrica::DoubleMatrica() {}
DoubleMatrica::DoubleMatrica(int aN, int aM) : n(aN), m(aM) {
	M = new double*[n];
	for (int i = 0; i < n; i++) 
		M[i] = new double[m];
}

DoubleMatrica::DoubleMatrica(int a) : n(a), m(a) {
	M = new double*[n];
	for (int i=0; i<n; i++)
		M[i] = new double[n];
}
	

DoubleMatrica::DoubleMatrica(const Matrica& mat)
		: n(mat.GetN()), m(mat.GetM()) {
	M = new double*[n];
	for (int i=0; i<n; i++)
		M[i] = new double[m];

	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++)
			M[i][j] = static_cast<double>(mat.Get(i, j));
}

DoubleMatrica::DoubleMatrica(const DoubleMatrica& mat)
		: n(mat.GetN()), m(mat.GetM()) {
	M = new double*[n];
	for (int i = 0; i < n; i++)
		M[i] = new double[m];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			M[i][j] = mat.Get(i, j);
}

DoubleMatrica::~DoubleMatrica() {
	for (int i = 0; i < n; i++)
		delete [] M[i];
	delete [] M;
}

void DoubleMatrica::Ispis() {
	for (int i = 0; i < n; i++) {
		cout << '\t';
		for (int j = 0; j < m; j++) {
			cout << M[i][j];
			if (j != m-1)
				cout << '\t';
		}
		cout << '\n';
	}	
	cout << '\n';
	return;
}

void DoubleMatrica::Set(int i, int j, double value) { M[i][j] = value; }
double*& DoubleMatrica::operator[](const int& index) { return  M[index]; }
double DoubleMatrica::Get(int i, int j) const { return M[i][j]; }
int DoubleMatrica::GetN(void) const { return n; }
int DoubleMatrica::GetM(void) const { return m; }

DoubleMatrica inv(const Matrica& mat) {
	int d = det(mat);
	if (d == 0)
		throw "Matrica je singularna.";
	else
		return 1.0/d * adj(mat);
}


DoubleMatrica operator*(double x, const Matrica& mat) {
	DoubleMatrica out(mat);
	for (int i=0; i<mat.GetN(); i++)
		for (int j=0; j<mat.GetM(); j++)
			out[i][j] *= x;
	return out;
}
