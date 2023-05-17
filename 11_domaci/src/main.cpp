#include <iostream>
#include <fstream>
#include <sciplot/sciplot.hpp>
// ------^^^^^^^^^^^^^^^^^^^^^------------------
// neophodno dodati kao Additional Include Dep...

namespace sc = sciplot;

std::vector<double> Smooth(const std::vector<double>& y, int dx) {
	std::vector<double> y2;
	int n = y.size();
	double sum;
	if (dx % 2 == 0)
		dx++;
	for (int i = 0; i < n; i++) {
		for (int j = i-dx/2; j <= i+dx/2; j++) {
			if (j > 0 && j < n)
				sum += y[j];
			else
				sum += y[i];
		}
		sum /= dx;
		y2.push_back(sum);
		sum = 0;
	}
	return y2;
}

inline double weight(const int i, const double n) {
	return i<0 ? ((double) i)/n + 1.0 : -((double) i)/n + 1.0;
}

std::vector<double> smooth_trougao(const std::vector<double>& a, const int n) {
	int i, j, size = a.size();
	std::vector<double> y(size);
	double okolina, accum = 0.0;

	for (i=0; i<size; ++i) {
		// smanjujemo okolinu da ne bi izasli van niza sa delovima okoline
		if (i<n)
			okolina = i;
		else if (i>size-1.0-n)
			okolina = size-1.0-i;
		else
			okolina = n;
		for (j = -okolina; j<=okolina; ++j)
			accum += weight(j, n) * a[i+j];
		// za konkretan primer trougla moze se pokazati da je
		// 		suma w_i od -n do n == n
		// --------------------V-----------------------------
		y[i] = accum/((double) n);
		accum = 0.0;
	}
	return y;
}

int main() {
	// konstruktor uzima ime file-a za koji zove open()
	std::ifstream myfile("xy_data.txt");
	std::vector<double> x, y;
	double xb, yb;

	// std::fstream& operator>>(..) vraca referencu na fstream
	// za fstream postoji 'operator bool' koji je sinonim za !fail()
	// metodu, samim tim mozemo da vrsimo ekstrakciju iz 'myfile'
	// putem operator>> i da to stavimo kao logicki uslov za petlju
	// zato sto petlja zove 'operator bool' reference fstream-a.
	while (myfile >> xb >> yb) {
		x.push_back(xb);
		y.push_back(yb);
	}
	myfile.close();

	sc::Plot2D plot;
	plot.gnuplot("set key box");

	plot.drawCurve(x, y).label("raw data");
	plot.drawCurve(x, Smooth(y, 20)).label("original sa casa, dx=20");
	// 2. parametar za smooth_trougao nije isti kao kod Smooth,
	// umesto dx -> n pa samim tim je n = dx/2
	plot.drawCurve(x, smooth_trougao(y, 10)).label("domaci, n=10");

	sc::Figure fig {{plot}};
	sc::Canvas canvas {{fig}};
	canvas.size(600, 600);
	canvas.show();

	return 0;
}
