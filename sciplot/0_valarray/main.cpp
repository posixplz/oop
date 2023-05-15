#include <iomanip>
#include <iostream>
#include <valarray>

int main() 
{
	std::valarray<int> data = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	std::cout << "Initial valarray\t";
	for (auto n : data)
		std::cout << std::setw(3) << n;
	std::cout << '\n';

	data[data > 6] = -1; // valarray<bool> overload of operator[]
	// the type of data > 6 is std::valarray<bool>
	// the type of data[data > 6] is std::mask_array<int>

	std::cout << "v[v > 6] = -1\t\t";
	for (std::size_t n = 0; n < data.size(); ++n) 
		std::cout << std::setw(3) << data[n]; // regular operator[]
	std::cout << '\n';

	std::cout << "data * 2\t\t";
	auto tmp = data;
	tmp *= 2;
	for (auto n : tmp)
		std::cout << std::setw(3) << n;
	std::cout << '\n';

	std::cout << "data - 1\t\t";
	tmp += -1;
	for (auto n : tmp)
		std::cout << std::setw(3) << n;
	std::cout << '\n';

	// https://en.cppreference.com/w/cpp/numeric/valarray/operator_arith3
	return 0;
}