#include <iostream>
#include <array>
#include "sfera.hpp"
#include <vector>

vector<Sfera*> niz;
vector<double> rOdKP;

void set(void);
void print(void);
void swapS(unsigned int, unsigned int);
void sort(void);
void pomak(double);
void rastojanja(void);
unsigned int  maxRastojanje(void);
unsigned int  minRastojanje(void);
void najbliziPar(void);

using namespace std;

int main(void) {
	// PP da je niz sfera tipa
	// x1 y1 z1 r1 x2 y2 z2 r2 x3...
	set();
	print();
	cout << "sort()" << endl;
	sort();
	print();
	rastojanja();
	cout << "Min rastojanje od KP ima sfera sa indeksom " <<
		minRastojanje() << endl;
	cout << "Max rastojanje od KP ima sfera sa indeksom " <<
		maxRastojanje() << endl;
	najbliziPar();
	return 0;
}

void set(void) {
	double x, y, z, r;
	while (cin >> x >> y >> z >> r) {
		niz.push_back(new Sfera({x,y,z}, r));
		cout << endl;
	}
	return;
}

void print(void) {
	array<double, 3> tmp;
	for (long unsigned int i = 0; i < niz.size(); i++) {
		tmp = niz.at(i)->getC();
		cout << i << "\t{" << tmp[0] << ", " << tmp[1] << ", "
			<< tmp[2] << "}, " << niz[i]->getR() << endl;
	}
	return;
}

void swapS(unsigned int i, unsigned int j) {
	auto tmp = niz.at(i);
	niz.at(i) = niz.at(j);
	niz.at(j) = tmp;

	return;
}

// imajuci u vidu da se zaprimina svodi na r^3
// mozemo samo da sortiramo po r
void sort(void) {
	bool flag;

	do {
		flag = false;
		for (unsigned int i=1; i<niz.size(); i++) {
			if (niz[i-1]->getR() < niz[i]->getR()) {
				swapS(i-1, i);
				flag = true;
			}
		}
	} while (flag);

	return;
}

void rastojanja(void) {
	for (const auto a : niz) {
		rOdKP.push_back(a->rastojanjeOdKP());
	}
	return;
}

unsigned int maxRastojanje(void) {
	double tmp = rOdKP.front();
	unsigned int pozicija;
	for (unsigned int i = 0; i < rOdKP.size(); i++) {
		if (rOdKP[i] > tmp) {
			tmp = rOdKP[i];
			pozicija = i;
		}
	}
	return pozicija;
}

unsigned int minRastojanje(void) {
	double tmp = rOdKP.front();
	unsigned int pozicija;
	for (unsigned int i = 0; i < rOdKP.size(); i++) {
		if (rOdKP[i] < tmp) {
			tmp = rOdKP[i];
			pozicija = i;
		}
	}
	return pozicija;
}

void najbliziPar(void) {
	unsigned int granica_i, i, j, min_i, min_j;
	double razlika, tmp;

	granica_i =  niz.size();
	min_i = i = 1;
	min_j = j = 0;
	tmp = rastojanjePeriferija(niz[i], niz[j]);

	for (i = 1; i < granica_i; i++){
		for (j = 0; j < i; j++) {
			razlika = rastojanjePeriferija(niz[i], niz[j]);
			if (razlika < tmp){
				min_i = i;
				min_j = j;
				tmp = razlika;
			}
		}
	}
	cout << "Najblizi par je " << min_i << " i " << min_j
		<< " sa rastojenjem " << tmp << endl;
	return;
}
