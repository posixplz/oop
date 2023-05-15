#include <sciplot/sciplot.hpp>
#include <numbers>
#include <valarray>

namespace sp = sciplot;

int main() {
    std::valarray<double> x = sp::linspace(0.0, 2.0 * std::numbers::pi, 200);

	sp::Plot2D plot;

	plot.gnuplot("set xtics axis");
	plot.gnuplot("set xzeroaxis");
	plot.xlabel("x");
	plot.ylabel("y");
	plot.yrange(-1.2, 1.2);
    
    plot.drawCurve(x, std::sin(x)).label("sin(x)");
	sp::Figure fig {{plot}};
	sp::Canvas canvas {{fig}};

	canvas.size(600, 600);
	canvas.show();
	return 0;
}
