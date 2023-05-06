#include <iostream>
#include <fstream>
#include <string>
#include "file.hpp"
#include "matrica.hpp"
#include <cstring>

using namespace std;


int main(int argc, char **argv) {
	File fa("matricaA.txt");
	File fb("matricaB.txt");
	File fc("matricaC.txt");
	if (!strcmp(argv[0], "init")) {
		init();
	} else {
	}
	return 0;
}

