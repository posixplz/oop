#pragma once
#include <iostream>
class Matrica
{

	//////////
private:
	int** M;
	int n, m;

public:
	Matrica() {}
	Matrica(int n, int m)
	{
		this->n = n;
		this->m = m;
		M = new int* [n];
		for (int i = 0; i < n; i++)
		{
			M[i] = new int[m];
		}
	}
	~Matrica()
	{	
		for (int i = 0; i < n; i++)
			delete[]M[i];
		delete[]M;
	}
	void Zeroes()
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				M[i][j] = 0;
	}
	void Random()
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				M[i][j] = rand();
	}
	void Ispis()
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
				std::cout << "M[" << i << "]" << "[" << j << "] = " << M[i][j] << " ";
			std::cout<<std::endl;
		}	
	}

	void Set(int i, int j, int value)
	{
		M[i][j] = value;
	}
	int Get(int i, int j)
	{
		return M[i][j];
	}
	//nedostaje copy konstruktor!!!!!!!!!!!!
	Matrica Saberi(Matrica const& matrica)
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
	friend Matrica Saberi2(Matrica const& m1, Matrica const& m2)
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
	Matrica operator+(Matrica const& matrica)
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
	Matrica(Matrica& object)
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
				M[i][j] = object.M[i][j];
	}

	Matrica& operator=(const Matrica& t) 	// preklapanje =
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

	int*& operator[](const int& index)  // overloading operator []
	{
		return  M[index];
	}


};

