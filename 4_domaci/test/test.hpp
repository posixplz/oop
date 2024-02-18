using namespace std;

class Test
{
private:
	array<double, 2> koord;
public:
	void set(char, double);
	void set(array<double, 2>);
	const array<double, 2>& get(void);
	Test(array<double, 2>);
	Test(double, double);
	~Test();
	void trans(array<double,2>);
	double in1(void);
	double in2(void);
	friend double rastojanje(Test&, Test&);
};
