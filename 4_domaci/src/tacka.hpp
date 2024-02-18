using namespace std;

class Tacka
{
private:
	array<double, 2> koordinate = {0.0, 0.0};
public:
	double get(int); // vraca samo jednu koordinatu
	const array<double, 2>& get(void);

	void set(double, double);
	void set(array<double, 2>);
	void set(int, double); // set-uje samo jednu koordinatu
	
	Tacka(double, double);
	Tacka(array<double, 2>);
	Tacka(int, double); // set-uje samo jednu koordinatu
	Tacka();

	~Tacka();

	void translacija(double, double);
	void translacija(array<double, 2>);

	friend double rastojanje(const Tacka&, const Tacka&);
};
