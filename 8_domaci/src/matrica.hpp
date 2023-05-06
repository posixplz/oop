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
	Matrica(const Matrica& original);
	~Matrica();

	void fill(const T);
	void random(const int min, const int max);
	void print(std::ostream&) const;
	void print() const;
	void print_mathematica_format() const;

	void set(std::array<std::size_t, 2>, const T value);
	void set(std::size_t red, std::size_t kolona, const T value);
	
	T get(std::array<std::size_t, 2>) const;
	T get(const std::size_t red, const std::size_t kolona) const;
	std::size_t get(dim) const;
	const std::array<std::size_t, 2>& get() const;
	
	Matrica& rmRed(const std::size_t red);
	Matrica& rmKol(const std::size_t kolona);
	Matrica bezRed(const std::size_t) const;
	Matrica bezKol(const std::size_t) const;

	Matrica& operator+= (const Matrica&);
	Matrica operator+ (const Matrica&);
	Matrica& operator= (const Matrica&);
	std::vector<T>& operator[] (std::size_t);
	Matrica operator* (const Matrica&) const;
	
	void jedinicna();
	T kofaktor(std::size_t red, std::size_t kolona) const;
	T minor(std::size_t red, std::size_t kolona) const;
	T det() const;
	Matrica kofaktorMatrica() const;
	Matrica tr() const;
	Matrica adj() const;
	Matrica<double> inv() const;
};

template<typename M, typename S>
Matrica<S> operator* (const Matrica<M>& matrica, const S skalar);

template<typename M, typename S>
Matrica<S> operator* (const S skalar, const Matrica<M>& matrica);

template<typename T>
void print(const Matrica<T>&);

template<typename T>
std::ostream& operator<< (std::ostream& os, const Matrica<T>& matrica);

//-----------------------------------------------------------------------------

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
void Matrica<T>::print(std::ostream& os) const {
	for (auto i = m.size(); const auto& kolona : m) {
		for (auto j = kolona.size(); const auto& element : kolona) {
			os << element;
			if (--j && !fieldseparator.empty()) {
				os << fieldseparator;
			}
		}
		if (--i && !recordseparator.empty())
			os << recordseparator;
	}	
	if (!endOfData.empty())
		os << endOfData;
}

template<typename T>
void Matrica<T>::print() const {
	print(std::cout);
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
	d = argM.get();
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

template<typename T>
Matrica<T>& Matrica<T>::rmRed(const std::size_t index_reda) {
	m.erase(m.begin()+index_reda);
	m.shrink_to_fit();
	--d[redova];
	return *this;
}

template<typename T>
Matrica<T>& Matrica<T>::rmKol(const std::size_t index_kolone) {
	for (auto& kolona : m) {
		kolona.erase(kolona.begin()+index_kolone);
		m.shrink_to_fit();
	}
	--d[kolona];
	return *this;
}

template<typename T>
Matrica<T>
Matrica<T>::bezRed(const std::size_t index_reda) const {
	Matrica<T> out(*this);
	return out.rmRed(index_reda);
}

template<typename T>
Matrica<T>
Matrica<T>::bezKol(const std::size_t index_kolone) const {
	Matrica<T> out(*this);
	return out.rmKol(index_kolone);
}
	
template<typename M, typename S>
Matrica<S> operator* (const Matrica<M>& matrica, const S skalar) {
	Matrica<S> out(matrica.get());
	for (std::size_t i=0; i<out.get(redova); i++)
		for (std::size_t j=0; j<out.get(kolona); j++)
			out[i][j] = matrica.get(i, j) * skalar;
	return out;
}

template<typename M, typename S>
Matrica<S> operator* (const S skalar, const Matrica<M>& matrica) {
	return matrica * skalar;
}

template<typename T>
T Matrica<T>::kofaktor(std::size_t red, std::size_t kolona) const {
	if ((red + kolona)%2)
		return -minor(red, kolona);
	else
		return minor(red, kolona);
}

template<typename T>
T Matrica<T>::minor(std::size_t red, std::size_t kolona) const {
	return bezRed(red).rmKol(kolona).det();
}

template<typename T>
T Matrica<T>::det() const {
	if (d[redova] != d[kolona])
		throw "Matrica nije kvadratna (n x n).";
	auto n = d[redova];
	if (n == 1)
		return get(0, 0);
	T out = (T) 0;
	for (std::size_t j=0; j<n; j++)
        out += get(0, j) * kofaktor(0, j);
    return out;
}
	
template<typename T>
Matrica<T> Matrica<T>::tr() const {
	Matrica<T> out(*this);
	for (std::size_t i=0; i<d[redova]-1; i++)
		for (std::size_t j=i+1; j<d[kolona]; j++)
			std::swap(out[i][j], out[j][i]);
	return out;
}

template<typename T>
Matrica<T> Matrica<T>::adj() const {
	return kofaktorMatrica().tr();
}

template<typename T>
Matrica<T> Matrica<T>::kofaktorMatrica() const {
	Matrica out(d);
	for (std::size_t i=0; i<out.get(redova); i++)
		for (std::size_t j=0; j<out.get(kolona); j++)
			out[i][j] = kofaktor(i, j);
	return out;
}

template<typename T>
Matrica<double> Matrica<T>::inv() const {
	if (det() == 0)
		throw "Matrica je singularna.";
	else
		return 1.0/det() * adj();
}

template<typename T>
void print(const Matrica<T>& matrica) {
	matrica.print();
	return;
}

template<typename T>
std::ostream& operator<< (std::ostream& os, const Matrica<T>& matrica) {
	matrica.print(os);
	return os;
}
