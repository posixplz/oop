#include <sciplot/sciplot.hpp>
#include <valarray>

namespace sp = sciplot;

// gnuplot.info

inline auto lorencijan(const std::valarray<double>& x,
		const double xc, const double h, const double w_pola) {
	return h/(1.0 + pow((x-xc)/w_pola, 2));
}

int main() {
	std::valarray<double> x = sp::linspace(-10.0, 10.0, 100);

	sp::Plot2D plot;
	plot.gnuplot("set key top right box width -5");
	plot.gnuplot("set termoption enhanced");
	plot.gnuplot("unset border");
	plot.gnuplot("set xzeroaxis");
	plot.gnuplot("set yzeroaxis");
	plot.gnuplot("set xtics axis");
	plot.gnuplot("set ytics axis");

	plot.drawCurve(x, lorencijan(x, 0.0, 2.0, 4.0))
		.label("f(x) = H/(1 + (x-x_c/w_{1/2})^2)");

	sp::Figure fig {{plot}};
	sp::Canvas canvas {{fig}};
	
	canvas.size(600, 600);
	canvas.show();
	return 0;
}
