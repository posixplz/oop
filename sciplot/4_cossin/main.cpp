#include <sciplot/sciplot.hpp>
#include <numbers>
#include <valarray>

namespace sp = sciplot;

int main() {
    std::valarray<double> x = sp::linspace(0.0, 2.0 * std::numbers::pi, 200);

	sp::Plot2D plot_sin, plot_cos;

	plot_sin.gnuplot("set xtics axis");
	plot_sin.gnuplot("set xzeroaxis");
	plot_sin.xlabel("x");
	plot_sin.ylabel("y");
	plot_sin.yrange(-1.2, 1.2);

	plot_cos.gnuplot("set xtics axis");
	plot_cos.gnuplot("set xzeroaxis");
	plot_cos.xlabel("x");
	plot_cos.ylabel("y");
	plot_cos.yrange(-1.2, 1.2);
    
    plot_sin.drawCurve(x, std::sin(x)).label("sin(x)");
    plot_cos.drawCurve(x, std::cos(x)).label("cos(x)");
	sp::Figure fig {{plot_sin, plot_cos}};
	sp::Canvas canvas {{fig}};

	canvas.size(1200, 600);
	canvas.show();
	return 0;
}
