#include <fstream>
#include <string>
#include "file.hpp"

using namespace std;

static constexpr auto default_mode = ios::in | ios::out | ios::app;

File::File(string fname) : fstream(fname, default_mode), fname_(fname) {}

const string& File::getFilename() const {
	return fname_;
}

void File::reopen(ios::openmode mode) {
	if (is_open())
		close();
	open(fname_, mode);
}

void File::set(const string& fname) {
	fname_ = fname;
	reopen(default_mode);
}

void File::erase() {
	reopen(ios::out | ios::trunc);
	reopen(default_mode);
}
