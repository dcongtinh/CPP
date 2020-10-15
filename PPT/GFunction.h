#include "GUtils.h"

typedef vector<double> GFunction;

GFunction makeFunction(int n, double *a)
{
	vector<double> result;
	for (int i = 0; i < n; ++i)
		result.push_back(a[i]);
	return result;
}

void fHornerProcess(GFunction &f, int toDeg, double alpha)
{

	if (f.size() == 0)
		return;

	double b = f[f.size() - 1];
	for (int i = (int)f.size() - 2; i >= toDeg; --i)
	{

		f[i] = b = b * alpha + f[i];
	}
}

double fValueAt(GFunction f, double alpha)
{
	// change this method to calculate more complicated function
	// calculating value follows Horner method

	if (f.size() == 0)
		return 0;

	fHornerProcess(f, 0, alpha);
	return f[0];
}

ll factorial(int n)
{
	ll result = 1;
	for (int i = 2; i <= n; ++i)
		result *= i;
	return result;
}

double fDerivationAt(GFunction f, int n, double alpha)
{

	if (n >= f.size())
		return 0;

	for (int i = 0; i <= n; ++i)
	{
		fHornerProcess(f, i, alpha);
	}

	return factorial(n) * f[n];
}

GFunction inputFunction()
{
	cout << "f(x) = a[0] + a[1]*x + a[2]*x^2 + .. + a[n-1]*x^(n-1) + a[n]*x^n" << endl;
	GFunction result;
	int n = toNum<int>(input("Input n = "));
	for (int i = 0; i <= n; ++i)
	{
		double a_i = toNum<double>(input("a" + toString(i) + " = "));
		result.push_back(a_i);
	}
	return result;
}

void print(GFunction f)
{
	cout << "f(x) = ";
	for (int i = 0; i < f.size(); ++i)
	{

		if (f[i] == 0)
			continue;

		if (i == 0 || f[i] != 1)
			cout << f[i];
		if (i > 0)
			cout << "x";
		if (i > 1)
			cout << "^" << i;
		if (i != f.size() - 1)
			cout << " + ";
	}
	cout << endl;
}
