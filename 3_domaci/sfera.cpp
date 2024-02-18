#include <array>
#include "sfera.hpp"
#include <cmath>
#include <numbers>
#include <numeric>
#include <algorithm>

using namespace std;

Sfera::Sfera(array<double, 3> C, double R) {
	this->koordinate = C;
	this->poluprecnik = R;
}

Sfera::Sfera(double x, double y, double z, double R){
	this->koordinate = {x, y, z};
	this->poluprecnik = R;
}

Sfera::Sfera(void) {
	this->koordinate.fill(0.0);
	this->poluprecnik = 0.0;
}

Sfera::~Sfera(){}

// get i set atributa
double Sfera::getR(void){
	return this->poluprecnik;
}
array<double, 3> Sfera::getC(void){
	return this->koordinate;
}

void Sfera::setR(double R){
	this->poluprecnik = R;
	return;
}
void Sfera::setC(array<double, 3> C){
	this->koordinate = C;
	return;
}
void Sfera::setC(double x, double y, double z){
	this->setC({x, y, z});
	return;
}

// dodatne metode
double Sfera::povrsina(void){
	return 4.0 * pow(this->poluprecnik, 2) * numbers::pi;
}
double Sfera::zapremina(void){
	return 4.0 * pow(this->poluprecnik, 3) * numbers::pi / 3.0;
}

void Sfera::translacija(array<double, 3> C){
	transform(C.cbegin(), C.cend(), this->koordinate.cbegin(), this->koordinate.begin(), plus<>{});
	return;
}
void Sfera::translacija(double x, double y, double z){
	this->translacija({x,y,z});
	return;
}

double Sfera::rastojanjeOdKP(void){
	return sqrt(inner_product(this->koordinate.begin(), this->koordinate.end(), this->koordinate.begin(), 0));
}

// friend
double rastojanjePeriferija(Sfera *s1, Sfera *s2){
	auto C1 = s1->getC();
	auto C2 = s2->getC();
	transform(C1.cbegin(), C1.cend(), C2.cbegin(), C2.begin(), minus<>{});
	auto tmp = sqrt(inner_product(C2.begin(), C2.end(), C2.begin(), 0)) - s1->getR() - s2->getR();
	if (tmp < 0.0) 
		return abs(s1->getR() - s2->getR());
	else
		return tmp;
}
