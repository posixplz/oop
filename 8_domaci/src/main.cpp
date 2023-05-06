#include <iostream>
#include <fstream>
#include <string>
#include "file.hpp"
#include "matrica.hpp"
#include <sstream>
#include <cstring>

using namespace std;

template<typename T>
File& operator>>(File& file, Matrica<T>& m) {
	string linebuf;
	stringstream ss;
	T tmp;
	while (getline(file, linebuf)) {
		ss.clear();
		ss << linebuf;
		while (ss >> tmp)
			m << tmp;
		if (linebuf.empty())
			break;
		m << '\n';
	}
	m.pop();
	return file;
}

inline void init(File& fa, File& fb, File& fc, size_t n) {
	Matrica<int> tmp(n);
	tmp.random(0, 9);
	fa.erase();
	fa << tmp;
	tmp.random(0, 9);
	fb.erase();
	fb << tmp;
	fc.erase();
	fc << '\0';
	return;
}

int main(int argc, char **argv) {
	Matrica<double> A, B, C;
	File fa("matricaA.txt");
	File fb("matricaB.txt");
	File fc("matricaC.txt");

	if (argc > 1 && strcmp(argv[1], "init") == 0) {
		init(fa, fb, fc, 5);
		return 0;
	}

	fa >> A;
	fa << A.det() << '\n';
	fb >> B;
	fb << B.det() << '\n';
	fc << A*B;
	return 0;
}
