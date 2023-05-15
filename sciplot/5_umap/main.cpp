#include <sciplot/sciplot.hpp>
#include <numbers>
#include <iostream>
#include <ranges>
#include <memory>
#include <valarray>

namespace sp = sciplot;

int main() {
    std::valarray<double> x = sp::linspace(0.0, std::numbers::pi, 200);

    std::unordered_map<std::string, std::unique_ptr<sp::Plot2D>> plots;
	plots["sve"] = std::make_unique<sp::Plot2D>();
	plots["paran"] = std::make_unique<sp::Plot2D>();
	plots["neparan"] = std::make_unique<sp::Plot2D>();

    for (auto& [ime, plot] : plots) {
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
    auto paran = [](const auto& a) { return a%2==0; };
	std::valarray<double> tmp;
    for (auto i : std::views::iota(1, 7)) {
    	ss_label << "sin(" << i << "x)";
	    plots["sve"]->drawCurve(x, std::sin(i*x)).label(ss_label.str());
    	if (paran(i))
		    plots["paran"]->drawCurve(x, std::sin(i * x)).label(ss_label.str());
	    else
		    plots["neparan"]->drawCurve(x, std::sin(i * x)).label(ss_label.str());
	    ss_label.str(std::string());
	}

	sp::Figure fig {{*plots["paran"], *plots["neparan"]}, {*plots["sve"]}};
	sp::Canvas canvas {{fig}};

	canvas.size(600, 600);
	canvas.show();
	return 0;
}
