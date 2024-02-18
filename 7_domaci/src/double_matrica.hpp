#pragma once
#include "matrica.hpp"

class DoubleMatrica
{
private:
	double **M = nullptr;
	int n;
	int m;

public:
	DoubleMatrica();
	DoubleMatrica(int n, int m);
	DoubleMatrica(int n);
	DoubleMatrica(const Matrica& object);
	DoubleMatrica(const DoubleMatrica& object);
	~DoubleMatrica();

	void Set(int i, int j, double value);
	double Get(int i, int j) const;
	int GetN(void) const;
	int GetM(void) const;
	
	void Ispis();
	double*& operator[](const int& index);
};

DoubleMatrica inv(const Matrica& mat);
DoubleMatrica operator*(double x, const Matrica& mat);
