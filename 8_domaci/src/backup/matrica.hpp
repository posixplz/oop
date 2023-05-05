#include <iostream>
#include <random>
#include <array>
#include <vector>

constexpr enum dim { redova=0, kolona=1 };

template<typename T>
class Matrica
{
private:
	std::vector<std::vector<T>> m;
	std::array<std::size_t, 2> d;
public:
	Matrica();
	Matrica(std::array<std::size_t, 2>);
	Matrica(std::size_t redova, std::size_t kolona);
	Matrica(std::size_t dimenzija); // kvadratna
	Matrica(const Matrica& object);
	~Matrica();

	void fill(T);
	void random(int min, int max);
	void print(char fieldseparator) const;
	void print_mathematica_format() const;

	void set(std::array<std::size_t, 2>, T value);
	void set(std::size_t red, std::size_t kolona, T value);
	T getVal(std::array<std::size_t, 2>) const;
	T getVal(std::size_t red, std::size_t kolona) const;
	std::size_t getDim(dim) const;
	const array<std::size_t, 2>& getDim() const;
	
	/*
	Matrica operator+ (const Matrica&);
	Matrica& operator= (const Matrica&);
	T*& operator[] (std::size_t);
	*/

	/*
	Matrica operator*(const Matrica&);
	Matrica operator*(int);
	void jedinicna(void);
	Matrica& rmRed(int red);
	Matrica& rmKol(int kolona);
	friend Matrica c_rmRed(const Matrica& m, int red);
	friend Matrica c_rmKol(const Matrica& m, int kolona);
	int kofaktor(int i, int j) const;
	int minor(int i, int j) const;
	friend int det(const Matrica&);
	friend Matrica kofaktorMatrica(const Matrica& m);
	Matrica& transp(void);
	friend Matrica adj(const Matrica& m);
	*/
};

template<typename T>
Matrica<T>::Matrica() {}

template<typename T>
Matrica<T>::Matrica(std::array<std::size_t, 2> arg)
	: m(arg[redova], vector<T>(arg[kolona])), d(arg) {}

template<typename T>
Matrica<T>::Matrica(std::size_t r, std::size_t k)
	: m(r, vector<T>(k)), d({r, k}) {}

template<typename T>
Matrica<T>::Matrica(std::size_t D) : m(D, vector<T>(D)), d({D, D}) {}

template<typename T>
Matrica<T>::Matrica(const Matrica& M)
	: m(M.getDim(redova), vector<T>(M.getDim(kolona))), d(M.getDim())
{
	d 
}

template<typename T>
Matrica<T>::~Matrica() {}
	
template<typename T>
void Matrica<T>::fill(T value) {
	for (auto& kolona : m)
		for (auto& element : kolona)
			element = value;
}

template<typename T>
void Matrica<T>::random(int min, int max) {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> distr(min, max);
	for (auto& kolona : m)
		for (auto& element : kolona)
			element = distr(gen);
}

template<typename T>
void
Matrica<T>::print(char fieldseparator, char recordseparator, char eod)
const {
	for (const auto& kolona : m) {
		for (const auto& element : kolona) {
			std::cout << element;
			if (element != kolona.back())
				std::cout << fieldseparator;
		}
		std::cout << recordseparator;
	}	
	std::cout << eod;
}

template<typename T>
void Matrica<T>::print_mathematica_format() const {
	std::cout << "{";
	for (const auto& kolona : m) {
		std::cout << '{';
		for (const auto& element : kolona) {
			std::cout << element;
			if (element != kolona.back())
				std::cout << ", ";
		}
		std::cout << '}';
		if (kolona != m.back())
			std::cout << ", ";
	}	
	std::cout << "}\n";
	return;
}

template<typename T>
void Matrica<T>::set(std::array<std::size_t, 2> argarr, T value) {
	m[argarr[0]][argarr[1]] = value;
}

template<typename T>
void Matrica<T>::set(std::size_t red, std::size_t kolona, T value) {
	m[red][kolona] = value;
}

template<typename T>
T Matrica<T>::getVal(std::array<std::size_t, 2> argarr) const {
	return m[argarr[0]][argarr[1]];
}

template<typename T>
T Matrica<T>::getVal(std::size_t red, std::size_t kolona) const {
	return m[red][kolona];
}

template<typename T>
std::size_t Matrica<T>::getDim(dim) const {
	return d[dim];
}

template<typename T>
const array<std::size_t, 2>& Matrica<T>::getDim() const {
	return d;
}
