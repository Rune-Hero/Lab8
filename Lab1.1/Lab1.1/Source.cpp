#include <iostream>
#include <cmath>

using namespace std;

class functions
{
private:
	double x, y, z;

public:
	functions(int N)
	{
		x = 0.48 * N;
		y = 0.47 * N;
		z = -1.32 * N;
	}

	double function_b()
	{
		return (2 * z + cos(pow(fabs(y - 3 * x), 1. / 3))) / (2.1 + pow(sin(pow(fabs(pow(z, 3) - y), 0.2)), 2)) + pow(log(fabs((z - x) / (z + x))), 2);
	}
	double function_a(double b)
	{
		return pow(fabs(x), 0.43) + (exp(y - x) + sqrt(pow(fabs(y * y + b), 0.22))) / (1 + x * x * fabs(y - pow(tan(z), 2)));
	}

	void functionsRes()
	{
		double b = function_b();
		double a = function_a(b);

		cout << "x = " << x << endl;
		cout << "y = " << y << endl;
		cout << "z = " << z << endl;
		cout << "a[x,y,z,b] = " << a << endl;
		cout << "b[x,y,z] = " << b << endl;
	}
};

int main()
{
	int N = 2;

	functions F(N);
	F.functionsRes();

	return 0;
}