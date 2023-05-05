#include <iostream>
#include <fstream>
#include <string>
#include "file.hpp"
using namespace std;

int main() {
	string s;
	File f("proba");

	//f << "1 2 3\n";
	//f << "4 5 6\n";
	//f << "7 8 9\n";

	f >> skipws;
	f >> s;
	cout << s;
	/*
	f.reset();
	stringstream line;
	for (; getline(f, line);) {
		while (line >> s)
			cout << s;
		cout << '\n';
	}
	*/

	return 0;
}

