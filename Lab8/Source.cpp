#include <iostream>
#include <vector>
#include <algorithm>
#include <windows.h>

using namespace std;

int main()
{	
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	vector<int> v = {-5, 0, 23, 7, -3, 6, 32, 0, 54, -3};
	
	cout << "Масив: " << endl;
	for (auto i = v.begin(); i != v.end(); ++i)
		cout << *i << " ";

	int P = 1;
	int index = 0;
	for_each(v.begin(), v.end(), [&P, &index ](int val) {
		if (index % 2 == 0) P *= val;
		index++;
		});
	cout << "\nДобуток елементів масиву з парними номерами: " << P << endl;


	auto i1 = find(v.begin(), v.end(), 0);
	auto i2 = find(v.rbegin(), v.rend(), 0).base() - 1;

	int S = 0;
	if (i1 < i2)
		for_each(i1, i2, [&S](int val) { S += val; });

	cout << "\nСума елементів між першим і останнім нулями: " << S << endl;

	return 0;
}