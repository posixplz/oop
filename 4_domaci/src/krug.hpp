#include <array>
#include "tacka.hpp"

using namespace std;

class Krug
{
private:
	double r = 0.0;
public:
	Tacka centar;

	void setR(double);
	double getR(void);
	
	Krug(array<double, 2>, double);
	Krug(double, double, double);
	Krug();
	~Krug();

	double povrsina(void);
	double obim(void);

	friend double rastojanje(const Krug&, const Krug&);
};
