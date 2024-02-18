#pragma once

class Matrica
{
private:
	// dodata inicijalizacija atributa kako bi se izbeglo
	// potencijalno pristupanje neinicijalizovanim variablama
	int **M = nullptr;
	int n = 0;
	int m = 0;

public:
	Matrica();
	Matrica(int n, int m);
	Matrica(int n);
	Matrica(const Matrica& object);
	~Matrica();

	void Zeroes();
	void Random();
	void Ispis();

	void Set(int i, int j, int value);
	int GetN(void) const;
	int GetM(void) const;
	int Get(int i, int j) const;
	// -------------------^^^^^----------------------------
	// dodatak: nephodno deklaristai da je const metoda,
	// inace nije moguce pozvati istu za const Matrica type

	//nedostaje copy konstruktor!!!!!!!!!!!!
	Matrica Saberi(Matrica const& matrica);
	friend Matrica Saberi2(Matrica const& m1, Matrica const& m2);

	Matrica operator+(Matrica const& matrica);
	// preklapanje =
	Matrica& operator=(const Matrica& t);
	// overloading operator []
	int*& operator[](const int& index);



	Matrica operator*(const Matrica&);
	Matrica operator*(int);
	void jedinicna(void);
	Matrica& rmRed(int red);
	Matrica& rmKol(int kolona);
	friend Matrica c_rmRed(const Matrica& m, int red);
	friend Matrica c_rmKol(const Matrica& m, int kolona);
	int kofaktor(int i, int j) const;
	int minor(int i, int j) const;
	friend int det(const Matrica&);
	void print_mathematica_format(void) const;
	friend Matrica kofaktorMatrica(const Matrica& m);
	Matrica& transp(void);
	friend Matrica adj(const Matrica& m);
};
