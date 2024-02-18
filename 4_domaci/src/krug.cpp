#include "krug.hpp"
#include <cmath>
#include <numbers>

void Krug::setR(double a) {
	this->r = a;
	return;
}

double Krug::getR(void) {
	return this->r;
}

Krug::Krug(array<double, 2> A, double R) {
	this->centar.set(A);
	this->r = R;
}

Krug::Krug(double X, double Y, double R) {
	this->centar.set(X, Y);
	this->r = R;
}

Krug::Krug() {}

Krug::~Krug() {}

double Krug::povrsina(void) {
	return pow(this->r, 2) * numbers::pi;
}

double Krug::obim(void) {
	return 2.0 * this->r * numbers::pi;
}

double rastojanje(const Krug& k1, const Krug& k2) {
	double d = rastojanje(k1.centar, k2.centar);

	if (d < abs(k1.r - k2.r))
		// ako je rastojenje centra krugova manje
		// od |r1-r2| onda jedan krug obuhvata drugi, tj
		// jedan je unutar drugog tako da se neseku kruznice,
		// to oznacavamo tako sto vracamo negativnu vrednost
		return -(abs(k1.r - k2.r) - d);
	else if (d > k1.r + k2.r)
		return d - (k1.r + k2.r);
	else
		// ako je rastojenje centra krugova izmedju
		// |r1-r2| i r1+r2 onda se kruznice seku,
		// to oznacavamo tako sto vratimo 0.0
		return 0.0;
}

