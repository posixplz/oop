#include <sciplot/sciplot.hpp>
#include <valarray>

namespace sp = sciplot;

// https://sciplot.github.io/
// gnuplot.info

int main() {
	std::valarray<double> x = sp::linspace(-10.0, 10.0, 100);

	sp::Plot2D plot;
	plot.gnuplot("set key right bottom box");
	
	plot.drawCurve(x, 7*x + 5).label("linearna");
	plot.drawCurve(x, pow(x, 2)).label("kvadratna");

	sp::Figure fig {{plot}};
	sp::Canvas canvas {{fig}};
	
	canvas.size(600, 600);
	canvas.show();
	return 0;
}
