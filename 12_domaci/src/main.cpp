/*	char   hex
	Ć      c4 86
	ć      c4 87
	Č      c4 8c
	č      c4 8d
	Đ      c4 90
	đ      c4 91
	Š      c5 a0
	š      c5 a1
	Ž      c5 bd
	ž      c5 be
*/
#include <iostream>
#include <tuple>
#include <map>
#include <fstream>
#include <sciplot/sciplot.hpp>
#include <cctype>
#include <string>
#include <sstream>

#define FILEPATH	"../Kraj vecnosti - Isaac Asimov.txt"
#define RS_MS_BYTE	0xc4

namespace sp = sciplot;

union karakter {
	char c;
	char16_t w;
	void clear_ms_byte() {
		w &= 0x00ff;
	}
	void set_ms_byte(const char a) {
		clear_ms_byte();
		w |= (char16_t) a << 8;
	}
	std::tuple<char, char> wget() const {
		return {c, (char) (w >> 8)};
	}
};

inline bool operator< (const karakter a, const karakter b) {
	return a.w < b.w;
}

int main() {
	char d;
	karakter k;
	std::ifstream file(FILEPATH);
	std::map<karakter, unsigned long> raspodela;

	while (file.get(k.c)) {
		if ((unsigned char) k.c >= RS_MS_BYTE) {
			file.get(d);
			k.set_ms_byte(d);
		} else {
			if (!std::isalnum(k.c))
				continue;
			k.clear_ms_byte();
		}
		raspodela[k]++;
	}

	sp::Plot2D plot, plotlog;
	plot.gnuplot("set encoding utf8");
	plot.gnuplot("set key box");
	plot.gnuplot("set style fill solid border -1");
	plotlog.gnuplot("set encoding utf8");
	plotlog.gnuplot("set key box");
	plotlog.gnuplot("set style fill solid border -1");

	const std::size_t s = raspodela.size();
	std::vector<unsigned long> y(s);
	std::vector<std::string> labels(s);
	std::stringstream ss;

	for (std::size_t i=0; const auto& [ch, num] : raspodela) {
		if ((unsigned char) ch.c >= RS_MS_BYTE) {
			auto [m, n] = ch.wget();
			std::cout << m << n;
			ss << m << n;
		} else {
			std::cout << ch.c;
			ss << ch.c;
		}
		std::cout << ' ' << num << '\n';
		labels[i] = ss.str();
		ss.str(std::string());
		y[i++] = num;
	}

	plot.drawBoxes(labels, y).label("učestalost slova");
	plotlog.drawBoxes(labels, y).label("učestalost slova");
	plotlog.ytics().logscale(10);
	plot.boxWidthRelative(0.75);
	plotlog.boxWidthRelative(0.75);
	
	sp::Figure fig {{plot}, {plotlog}};
	sp::Canvas canvas {{fig}};
	canvas.size(1400, 700);
	canvas.show();

	return 0;
}
