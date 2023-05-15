#include <sciplot/sciplot.hpp>
#include <numbers>
#include <iostream>
#include <ranges>
#include <memory>
#include <valarray>
#include <array>

namespace sp = sciplot;

namespace p {
	enum { sve=0, paran, neparan };
}

auto helix_plot(const double frek = 2.0, const double radius = 1.0) {
	std::valarray<double> z = sp::linspace(0.0, 10.0, 2000);
	std::valarray<double> x = radius * std::cos(frek * z);
	std::valarray<double> y = radius * std::sin(frek * z);

	sp::Plot3D plot;
	plot.drawCurve(x, y, z);

	plot.legend().hide();
	plot.xlabel("x");
	plot.ylabel("y");
	plot.zlabel("z");
	const double range = 1.1*radius;
	plot.xrange(-range, range);
	plot.yrange(-range, range);

	// Clear all borders and set the visible ones
	plot.border().clear();
	plot.border().bottomLeftFront();
	plot.border().bottomRightFront();
	plot.border().leftVertical();
	return plot;
}

int main() {
    std::valarray<double> x = sp::linspace(0.0, std::numbers::pi, 200);

    std::array<std::unique_ptr<sp::Plot2D>, 3> plots;

    for (auto& plot : plots) {
    	plot = std::make_unique<sp::Plot2D>();
		plot->xlabel("x");
		plot->ylabel("y");
		plot->xrange(0.0, std::numbers::pi);
		plot->yrange(-1.0, 1.0);
		plot->legend()
			.atOutsideBottom()
			.displayHorizontal();
			//.displayExpandWidthBy(1);
	}
    
	std::stringstream ss_label;
	auto paran = [](const auto& a) { return a%2 == 0; };
	std::valarray<double> tmp;
	for (auto i : std::views::iota(1, 7)) {
    	ss_label << "sin(" << i << "x)";
	    plots[p::sve]->drawCurve(x, std::sin(i*x)).label(ss_label.str());
    	if (paran(i))
		    plots[p::paran]->drawCurve(x, std::sin(i * x)).label(ss_label.str());
	    else
		    plots[p::neparan]->drawCurve(x, std::sin(i * x)).label(ss_label.str());
	    ss_label.str(std::string());
	}

	sp::Figure fig {
		{*plots[p::paran], *plots[p::neparan]},
		{*plots[p::sve], helix_plot()}
	};
	sp::Canvas canvas {{fig}};

	canvas.size(600, 600);
	canvas.show();
	return 0;
}
