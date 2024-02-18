#pragma once
#include <iostream>

class Niz
{
//		Menjamo "private" u "protected" kako bi imali 
//		pristup nizu iz klase koja nasleđuje od ove
//
//	private:
	protected:
		int* A;
		int N;

	public:
		Niz()
		{
		}
		Niz(int _N)
		{
			N = _N;
			A = new int[N];

			for (int i = 0; i < N; i++)
			{
				A[i] = 0;
			}
		}
		Niz(int* _A, int _N)
		{
			A = _A;
			N = _N;
		}
		~Niz()
		{
			delete[]A;
		}

		//metoda
		void Set(int v, int index)
		{
			if (index < N && index >= 0)
				A[index] = v;
			else
				std::cout << "Greska, index je van opsega \n";
		}
		int Get(int index)
		{
			return A[index];
		}
		void Print()
		{
			for (int i = 0; i < N; i++)
			{
				std::cout << "A[" << i << "] = " << A[i] << std::endl;
			}
		}

		void Random()
		{
			for (int i = 0; i < N; i++)
			{
				A[i] = rand();
			}
		}

		void Resize(int _N)
		{
			delete[]A;
			A = new int[_N];
			N = _N;

		}
};
