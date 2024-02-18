#include <iostream>
#include <new>
#include "matrica.hpp"
#include "double_matrica.hpp"
#include <random>

using namespace std;

Matrica::Matrica() {}
Matrica::Matrica(int n, int m)
{
	this->n = n;
	this->m = m;
	M = new int* [n];
	for (int i = 0; i < n; i++)
	{
		M[i] = new int[m];
	}
}

Matrica::Matrica(int a) {
	m = n = a;
	M = new int* [n];
	for (int i=0; i<n; i++)
		M[i] = new int[n];
}
	

Matrica::Matrica(const Matrica& object)
{
	n = object.n;
	m = object.m;

	M = new int* [n];
	for (int i = 0; i < n; i++)
	{
		M[i] = new int[m];
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			M[i][j] = object.Get(i, j);
}

Matrica::~Matrica()
{	
	for (int i = 0; i < n; i++)
		delete[]M[i];
	delete[]M;
}

void Matrica::Zeroes()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			M[i][j] = 0;
}

void Matrica::Random()
{
	// malo normlniji radnom brojevi
	// od 0 do 20
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> distr(0, 20);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			M[i][j] = distr(gen);
			//M[i][j] = rand();
}

void Matrica::Ispis()
{
	// promenjen ispis, malo laksi za citanje
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


void Matrica::Set(int i, int j, int value)
{
	M[i][j] = value;
}

// dodatak "const", vise detalja u matrica.hpp
//-----------------------------vvvvv----------
int Matrica::Get(int i, int j) const
{
	return M[i][j];
}

int Matrica::GetN(void) const { return n; }
int Matrica::GetM(void) const { return m; }

//nedostaje copy konstruktor!!!!!!!!!!!!
Matrica Matrica::Saberi(Matrica const& matrica)
{
	Matrica out(n, m);
	if (n == matrica.n && m == matrica.m)
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				out.M[i][j] = M[i][j] + matrica.M[i][j];
	}
	else
	{
		std::cout << "Greska";
	}
	return out;
}

Matrica Saberi2(Matrica const& m1, Matrica const& m2)
{
	Matrica out(m1.n, m1.m);
	if (m1.n == m2.n && m1.n == m2.m)
	{
		for (int i = 0; i < m1.n; i++)
			for (int j = 0; j < m1.m; j++)
				out.M[i][j] = m1.M[i][j] + m2.M[i][j];
	}
	else
	{
		std::cout << "Greska";
	}
	return out;
}

Matrica Matrica::operator+(Matrica const& matrica)
{
	Matrica out(n, m);
	if (n == matrica.n && m == matrica.m)
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				out.M[i][j] = M[i][j] + matrica.M[i][j];
	}
	else
	{
		std::cout << "Greska";
	}
	return out;	

}


Matrica& Matrica::operator=(const Matrica& t) 	// preklapanje =
{
	//ako se dodeljuje samom sebi, tada ne radi nista
	if (&t == this)
		return *this;
	//brisemo postojecu matricu iz memorije
	for (int i = 0; i < n; i++)
		delete[] M[i];
	delete[]M;

	//definisemo novu matricu _matrix
	n = t.n;
	m = t.m;

	M = new int* [n];
	for (int i = 0; i < n; i++)
		M[i] = new int[m];

	for (int i = 0; i < t.n; i++)
		for (int j = 0; j < t.m; j++)
		{
			M[i][j] = t.M[i][j];
		}
	return *this; //vraca se vrednost tekuceg objekta
}


int*& Matrica::operator[](const int& index) // overloading operator []
{
	return  M[index];
}

///////////////////////////////////////////////////////////////////////////////

Matrica Matrica::operator*(const Matrica& B) {
	Matrica out(m, B.n);
	if (m != B.n)
		throw	"Mnozenje matrica nije moguce, "
			"matrice nisu odgovarajuceg formata.";
	for (int i=0; i<n; i++) {
		for (int j=0; j<B.m; j++) {
			out[i][j] = 0;
			for (int k=0; k<m; k++) {
			out[i][j] += Get(i, k) * B.Get(k, j);
			}
		}
	}
	return out;
}

void Matrica::jedinicna(void) {
	if (n != m)
		throw "Matrica nije kvadratna (n x n).";
	Zeroes();
	for (int i = 0; i < n; i++)
			M[i][i] = 1;
	return;
}

Matrica& Matrica::rmRed(int red) {
	int i, j;
	int **nova = new int*[--n];
	for (i=0, j=0; i<n; i++, j++) {
		if (j == red)
			j++;
		nova[i] = M[j];
	}
	delete [] M;
	M = nova;
	return *this;
}

Matrica& Matrica::rmKol(int kolona) {
	int i, j, k;
	int **nova = new int*[n];
	m--;
	for (i=0; i<n; i++) {
		nova[i] = new int[m];
		for (j=0, k=0; j<m; j++, k++) {
			if (k == kolona)
				k++;
			nova[i][j] = M[i][k];
		}
		delete [] M[i];
	}
	delete [] M;
	M = nova;
	return *this;
}

Matrica c_rmRed(const Matrica& m, int red) {
	Matrica out(m);
	return out.rmRed(red);
}

Matrica c_rmKol(const Matrica& m, int kolona) {
	Matrica out(m);
	return out.rmKol(kolona);
}

int det(const Matrica& m) {
	if (m.n != m.m)
		throw "Matrica nije kvadratna (n x n).";
	if (m.n == 1)
		return m.Get(0, 0);
	int det = 0;
	for (int j=0; j<m.n; j++)
        det += m.Get(0, j) * m.kofaktor(0,j);
    return det;
}

int Matrica::kofaktor(int i, int j) const {
	if ((i+j)%2) {
		return -minor(i, j);
	} else {
		return minor(i, j);
	}
}

int Matrica::minor(int i, int j) const {
	return det(c_rmKol(c_rmRed(*this, i), j));
}

void Matrica::print_mathematica_format(void) const {
	cout << "\t{";
	for (int i = 0; i < n; i++) {
		cout << '{';
		for (int j = 0; j < m; j++) {
			cout << M[i][j];
			if (j != m-1)
				cout << ", ";
		}
		cout << '}';
		if (i != n-1)
			cout << ", ";
	}	
	cout << "}\n";
	return;
}

Matrica kofaktorMatrica(const Matrica& m) {
	if (m.n != m.m)
		throw "Matrica nije kvadratna (n x n).";
	Matrica out(m.n);
	for (int i=0; i<m.n; i++) {
		for (int j=0; j<m.n; j++) {
			out[i][j] = m.kofaktor(i, j);
		}
	}
	return out;
}

Matrica& Matrica::transp(void) {
	int **nova = new int*[m];
	for (int i=0; i<m; i++)
		nova[i] = new int[n];

	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			nova[j][i] = M[i][j];
		}
		delete [] M[i];
	}
	delete [] M;
	M = nova;
	swap(m, n);
	return *this;
}

Matrica adj(const Matrica& m) {
	return kofaktorMatrica(m).transp();
}
