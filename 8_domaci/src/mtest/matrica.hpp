/*
 * TODO:
 *		- revizija imena var i f-ja
 *		- dostupnost same matrice "m" member f-jama drugih obj,
 *			dosta bi smaljilo br f-ja
 *		- namespace za .*separator i EOD stringove ?
 *		- implementacija ostalih mat. f-ja
 */
#include <iostream>
#include <random>
#include <array>
#include <vector>
#include <string>

enum dim { redova=0, kolona=1 };

template<typename T>
class Matrica
{
private:
	std::vector<std::vector<T>> m;
	std::array<std::size_t, 2> d;
public:
	std::string fieldseparator = "\t";
	std::string recordseparator = "\n";
	std::string endOfData = "\n\n";

	Matrica();
	Matrica(std::array<std::size_t, 2>);
	Matrica(const std::size_t redova, const std::size_t kolona);
	Matrica(const std::size_t dimenzija); // kvadratna
	Matrica(const Matrica& object);
	~Matrica();

	void fill(const T);
	void random(const int min, const int max);
	void print() const;
	void print_mathematica_format() const;

	void set(std::array<std::size_t, 2>, const T value);
	void set(std::size_t red, std::size_t kolona, const T value);
	
	T get(std::array<std::size_t, 2>) const;
	T get(const std::size_t red, const std::size_t kolona) const;
	std::size_t get(dim) const;
	const std::array<std::size_t, 2>& get() const;
	
	Matrica& operator+= (const Matrica&);
	Matrica operator+ (const Matrica&);
	Matrica& operator= (const Matrica&);
	std::vector<T>& operator[] (std::size_t);

	void jedinicna();
	Matrica operator* (const Matrica&) const;
	
	/*
	Matrica& rmRed(const std::size_t red);
	Matrica& rmKol(const std::size_t kolona);
	friend Matrica c_rmRed(const Matrica& m, const std::size_t red);
	friend Matrica c_rmKol(const Matrica& m, const std::size_t kolona);
	Matrica operator* (T);


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
	: m(arg[redova], std::vector<T>(arg[kolona])), d(arg) {}

template<typename T>
Matrica<T>::Matrica(const std::size_t r, const std::size_t k)
	: m(r, std::vector<T>(k)), d({r, k}) {}

template<typename T>
Matrica<T>::Matrica(const std::size_t D) : m(D, std::vector<T>(D)), d({D, D}) {}

template<typename T>
Matrica<T>::Matrica(const Matrica& M) : m(M.m), d(M.d) {}

template<typename T>
Matrica<T>::~Matrica() {}
	
template<typename T>
void Matrica<T>::fill(const T value) {
	for (auto& kolona : m)
		for (auto& element : kolona)
			element = value;
}

template<typename T>
void Matrica<T>::random(const int min, const int max) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distr(min, max);
	for (auto& kolona : m)
		for (auto& element : kolona)
			element = distr(gen);
}

template<typename T>
void Matrica<T>::print() const {
	for (auto i = m.size(); const auto& kolona : m) {
		for (auto j = kolona.size(); const auto& element : kolona) {
			std::cout << element;
			if (--j && !fieldseparator.empty()) {
				std::cout << fieldseparator;
			}
		}
		if (--i && !recordseparator.empty())
			std::cout << recordseparator;
	}	
	if (!endOfData.empty())
		std::cout << endOfData;
}

template<typename T>
void Matrica<T>::print_mathematica_format() const {
	std::cout << "{";
	for (auto i = m.size(); const auto& kolona : m) {
		std::cout << '{';
		for (auto j = kolona.size(); const auto& element : kolona) {
			std::cout << element;
			if (--j)
				std::cout << ", ";
		}
		std::cout << '}';
		if (--i)
			std::cout << ", ";
	}	
	std::cout << "}\n";
	return;
}

template<typename T>
void Matrica<T>::set(std::array<std::size_t, 2> argarr, const T value) {
	m[argarr[0]][argarr[1]] = value;
}

template<typename T>
void Matrica<T>::set(std::size_t red, std::size_t kolona, T value) {
	m[red][kolona] = value;
}

template<typename T>
T Matrica<T>::get(std::array<std::size_t, 2> argarr) const {
	return m[argarr[0]][argarr[1]];
}

template<typename T>
T Matrica<T>::get(std::size_t red, std::size_t kolona) const {
	return m[red][kolona];
}

template<typename T>
std::size_t Matrica<T>::get(dim a) const {
	return d[a];
}

template<typename T>
const std::array<std::size_t, 2>& Matrica<T>::get() const {
	return d;
}

template<typename T>
Matrica<T>& Matrica<T>::operator+= (const Matrica& argM) {
	if (argM.d != d)
		throw "Matrice nisu istih dimenzija.";
	for (std::size_t i=0; i<m.size(); i++)
		for (std::size_t j=0; j<m.size(); j++)
			m[i][j] += argM.get(i, j);
	return *this;
}

template<typename T>
Matrica<T> Matrica<T>::operator+ (const Matrica& argM) {
	if (argM.d != d)
		throw "Matrice nisu istih dimenzija.";
	Matrica<T> out(*this);
	out += argM;
	return out;
}

template<typename T>
Matrica<T>& Matrica<T>::operator= (const Matrica& argM) {
	if (&argM == this)
		return *this;
	m.clear();
	for (const auto& kolona : argM.m)
		m.push_back(kolona);
	m.shrink_to_fit();
	return *this;
}

template<typename T>
std::vector<T>& Matrica<T>::operator[] (std::size_t index) {
	return m[index];
}

template<typename T>
void Matrica<T>::jedinicna() {
	if (d[redova] != d[kolona])
		throw "Matrica nije kvadratna.";
	for (std::size_t i=0; auto& kolona : m)
		kolona[i++] = 1;
}

template<typename T>
Matrica<T> Matrica<T>::operator*(const Matrica& B) const {
	if (d[kolona] != B.d[redova])
		throw "Matrice nisu odgovarajuceg formata.";
	Matrica<T> out(d[kolona], B.d[redova]);
	for (std::size_t i=0; i<d[redova]; i++) {
		for (std::size_t j=0; j<B.d[kolona]; j++) {
			out[i][j] = 0;
			for (int k=0; k<m; k++) {
			out[i][j] += get(i, k) * B.get(k, j);
			}
		}
	}
	return out;
}
/*
Matrica& Matrica::rmRed(int red) {
	int i, j;
	int **nova = new int*[--n];
	for (i=0, j=0; i<n; i++, j++) {
		if (j == red)
			j++;
		nova[i] = M[j];
	}
	delete [] M;
	M = nova;
	return *this;
}

Matrica& Matrica::rmKol(int kolona) {
	int i, j, k;
	int **nova = new int*[n];
	m--;
	for (i=0; i<n; i++) {
		nova[i] = new int[m];
		for (j=0, k=0; j<m; j++, k++) {
			if (k == kolona)
				k++;
			nova[i][j] = M[i][k];
		}
		delete [] M[i];
	}
	delete [] M;
	M = nova;
	return *this;
}

Matrica c_rmRed(const Matrica& m, int red) {
	Matrica out(m);
	return out.rmRed(red);
}

Matrica c_rmKol(const Matrica& m, int kolona) {
	Matrica out(m);
	return out.rmKol(kolona);
}

*/
