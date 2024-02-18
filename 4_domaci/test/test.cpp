#include <array>
#include <algorithm>
#include <numeric>
#include <cmath>
#include "test.hpp"

void Test::set(char a, double b) {
	switch (a) {
		case 'x':
			this->koord[0] = b;
			return;
		case 'y':
			this->koord[1] = b;
			return;
	}
	return;
}

void Test::set(array<double, 2> a) {
	this->koord = a;
	return;
}

const array<double, 2>& Test::get(void) {
	return this->koord;
}

Test::Test(array<double, 2> a) {
	this->set(a);
}

Test::Test(double a, double b) {
	this->set({a,b});
}

Test::~Test() {}

void Test::trans(array<double,2> a) {
	transform(a.cbegin(), a.cend(), this->koord.cbegin(), this->koord.begin(), plus<>{});
	return;
}

double Test::in1(void) {
	return inner_product(this->koord.cbegin(), this->koord.cend(), this->koord.cbegin(), 0.0);
}

double Test::in2(void) {
	return sqrt(inner_product(this->koord.cbegin(), this->koord.cend(), this->koord.cbegin(), 0.0));
}

double rastojanje(Test& t1, Test& t2) {
	array<double, 2> tmp;
	transform(t1.get().cbegin(), t1.get().cend(), t2.get().cbegin(), tmp.begin(), minus<>{});
	return sqrt(inner_product(tmp.cbegin(), tmp.cend(), tmp.cbegin(), 0.0));
}
