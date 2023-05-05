#include <iostream>
#include <array>
#include <vector>

using namespace std;

/*
class M
{
private:
};

*/
class C
{
private:
	array<size_t, 2> p;
public:
	C(array<size_t, 2>);
	C(size_t a, size_t b);
};

C::C(array<size_t, 2> arr) : p(arr) {
	cout << p[0] << ' ';
	cout << p[1] << '\n';
}

C::C(size_t a, size_t b) : p({a, b}) {
	cout << p[0] << ' ';
	cout << p[1] << '\n';
}

void printmat(const vector<vector<int>>& v) {
	for (size_t i = 0; i < v.size(); i++) {
		for (size_t j = 0; j < v[0].size(); j++) {
			cout << v[i][j];
			if (j != v[0].size()-1)
				cout << '\t';
		}
		cout << '\n';
	}	
	cout << '\n';
	return;
}

void matfill(vector<vector<int>>& mat, int val) {
	for (auto& kolona : mat)
		for (auto& element : kolona)
			element = val;
}

void printvec(const vector<int>& v) {
	for (const auto& e : v)
		cout << e << ' ';
	cout << '\n';
}

int main() {
	array<size_t, 2> a = {1, 2};
	C c(a), c2(3, 4);
	vector<vector<int>> mat(3, vector<int>(3, 1));
	vector<vector<int>> m1(3, vector<int>(3, 1));
	printmat(mat);
	matfill(mat, 77);
	printmat(mat);
	mat[0][1] = 3;
	printmat(mat);
	vector<int> test(3, 1);
	printvec(test);
	test.clear();
	printvec(test);
	test.push_back(2);
	printvec(test);
	cout << "test.size() = ";
	cout << test.size();
	cout << "\ntest.capacity() = ";
	cout << test.capacity();
	cout << '\n';
	test.push_back(2);
	test.push_back(2);
	test.push_back(2);
	test.push_back(2);
	printvec(test);
	cout << "test.size() = ";
	cout << test.size();
	cout << "\ntest.capacity() = ";
	cout << test.capacity();
	cout << '\n';
	return 0;
}
