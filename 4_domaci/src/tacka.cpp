#include <array>
#include "tacka.hpp"
#include <algorithm>
#include <numeric>
#include <cmath>

double Tacka::get(int a) {
	return this->koordinate.at(a);
}

const array<double, 2>& Tacka::get(void) {
	return this->koordinate;
}

void Tacka::set(array<double, 2> a) {
	this->koordinate = a;
	return;
}

void Tacka::set(double x, double y) {
	this->set({x,y});
	return;
}

void Tacka::set(int a, double b) {
	this->koordinate.at(a) = b;
	return;
}

Tacka::Tacka(array<double, 2> a) {
	this->set(a);
}

Tacka::Tacka(double x, double y) {
	this->set({x,y});
}

Tacka::Tacka(int a, double b) {
	this->set(a,b);
}

Tacka::Tacka() {}

Tacka::~Tacka() {}

void Tacka::translacija(double x, double y) {
	this->koordinate[0] += x;
	this->koordinate[1] += y;
	return;
}

void Tacka::translacija(array<double, 2> a) {
	translacija(a[0], a[1]);
	return;
}

double rastojanje(const Tacka& t1, const Tacka& t2) {
	array<double, 2> tmp;
	transform(t1.koordinate.cbegin(), t1.koordinate.cend(),
		t2.koordinate.cbegin(), tmp.begin(), minus<>{});
	return sqrt(
		inner_product(tmp.cbegin(), tmp.cend(), tmp.cbegin(), 0.0)
		);
}
