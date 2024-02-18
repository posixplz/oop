#pragma once
#include "Niz.h"

class DomaciNiz : public Niz
{
	protected:
		void swap(unsigned int i, unsigned int j) {
			int tmp;

			tmp = A[i];
			A[i] = A[j];
			A[j] = tmp;

			return;
		}

	public:
		using Niz::Niz;

		void sort(void) {
			bool flag;

			do {
				flag = false;
				for (int i=1; i<N; i++) {
					if (A[i-1] < A[i]) {
						swap(i-1, i);
						flag = true;
					}
				}
			} while (flag);

			return;
		}
};
