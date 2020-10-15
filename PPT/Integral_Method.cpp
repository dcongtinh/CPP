/* Tinh - Phuc */

#include "GFunction.h"

#define sqr(x) (double)(x) * (x)

int main()
{
	GFunction f = inputFunction();
	double a = toNum<double>(input("from a = "));
	double b = toNum<double>(input("to   b = "));
	double h, M, result;
	ll n;
	cout << endl
		 << "Integral - Trapezoid_Method: " << endl;
	n = toNum<ll>(input("Divide n = "));
	result = 0;
	h = (b - a) / n;
	for (int i = 0; i < n; ++i)
	{
		result += (fValueAt(f, (i + 1) * h + a) + fValueAt(f, i * h + a));
	}

	result = h * result / 2;
	M = max(fDerivationAt(f, 2, a), fDerivationAt(f, 2, b));
	printf("Result: %.6lf, with accuracy: %.6lf\n", result, M * (b - a) * sqr(h) / 12);

	cout << endl
		 << "Integral - Simpson_Method: " << endl;
	result = 0;

	n = toNum<ll>(input("Divide n = 2k = "));
	h = (b - a) / n;
	for (int i = 0; i < n / 2; ++i)
	{
		result += fValueAt(f, (i * 2) * h + a) + fValueAt(f, (i + 1) * 2 * h + a) + 4 * fValueAt(f, (i * 2 + 1) * h + a);
	}

	result = h * result / 3;
	M = max(fDerivationAt(f, 4, a), fDerivationAt(f, 4, b));
	printf("Result: %.6lf, with accuracy: %.6lf\n", result, M * (b - a) * sqr(sqr(h)) / 180);

	cout << endl
		 << "Integral - Newton_Method: " << endl;
	n = toNum<ll>(input("Divide n = 3k = "));
	h = (b - a) / n;
	result = 0;
	for (int i = 0; i < n / 3; ++i)
	{
		result += fValueAt(f, (i * 3) * h + a) + fValueAt(f, (i + 1) * 3 * h + a) + 3 * (fValueAt(f, (i * 3 + 1) * h + a) + fValueAt(f, (i * 3 + 2) * h + a));
		// cout << i * 3 << " " << (i + 1) * 3 << " " << (3 * i + 1) << " " << 3 * i + 2 << endl;
	}

	result = 3 * h * result / 8;
	M = max(fDerivationAt(f, 4, a), fDerivationAt(f, 4, b));
	printf("Result: %.6lf, with accuracy: %.6lf\n", result, M * (b - a) * sqr(sqr(h)) / 80);
}
