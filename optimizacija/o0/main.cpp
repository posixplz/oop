#include <iostream>
#include <vector>

void vec_init(std::vector<double>& v) {
	for (std::size_t i=0; i<10; i++)
		v.push_back((double) i * 2.0);
}

void vec_print(const std::vector<double>& v) {
	for (std::size_t i=0; i<v.size(); i++)
		std::cout << v[i] << '\n';
}

int main() {
	std::vector<double> vec;
	vec_init(vec);
	vec_print(vec);
	return 0;
}
