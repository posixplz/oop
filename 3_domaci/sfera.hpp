using namespace std;

class Sfera
{
private:
	array<double, 3> koordinate;
	double poluprecnik;
public:
	Sfera(array<double, 3> koordinate, double poluprecnik);
	Sfera(double x, double y, double z, double poluprecnik);
	Sfera();
	~Sfera(void);

	// get i set atributa
	double getR(void);
	array<double,3> getC(void);

	void setR(double poluprecnik);
	void setC(array<double, 3> koordinate);
	void setC(double x, double y, double z);

	// dodatne metode
	double povrsina(void);
	double zapremina(void);
	
	void translacija(array<double, 3> koordinate);
	void translacija(double x, double y, double z);

	double rastojanjeOdKP(void);

	// firend funkcija
	friend double rastojanjePeriferija(Sfera *s1, Sfera *s2);
};
