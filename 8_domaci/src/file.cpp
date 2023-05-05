#include <fstream>
#include <string>
#include "file.hpp"

using namespace std;

static constexpr auto mode = ios::in | ios::out | ios::app;

File::File(string filename) : fstream(filename, mode), fname(filename) {}

const string& File::getFilename() const {
	return fname;
}

void File::set(const string& filename) {
	fname = filename;
	clear();
	if (is_open())
		close();
	open(fname, mode);
}

void File::reset() {
	clear();
	seekg(0);
}
