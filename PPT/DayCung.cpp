/* Phuc */

#include "GFunction.h"

int main()
{

	GFunction f = inputFunction();
	double a = toNum<double>(input("from  a = "));
	double b = toNum<double>(input("to    b = "));
	double M, m, esp,
		pivot, fpivot;

	M = max(fDerivationAt(f, 1, a), fDerivationAt(f, 1, b));
	m = min(fDerivationAt(f, 1, a), fDerivationAt(f, 1, b));
	esp = toNum<double>(input("epsilon = "));
	double x, tmp;

	double d2f = fDerivationAt(f, 2, (a + b) / 2);

	if (d2f > 0)
	{
		if (fValueAt(f, a) > 0)
		{
			pivot = a;
			x = b;
		}
		else
		{
			pivot = b;
			x = a;
		}
	}
	else
	{
		if (fValueAt(f, a) < 0)
		{
			pivot = a;
			x = b;
		}
		else
		{
			pivot = b;
			x = a;
		}
	}
	fpivot = fValueAt(f, pivot);

	tmp = x;
	x = pivot - fpivot / (fValueAt(f, x) - fpivot) * (x - pivot);
	int d = 0;
	while ((M - m) / m * (x - tmp) > esp)
	{
		printf("%.5f   (|x%d - x*| > epsilon)\n", x, ++d);
		tmp = x;
		x = pivot - fpivot / (fValueAt(f, x) - fpivot) * (x - pivot);
	}
	printf("%#.5f   (|x%d - x*| > epsilon)\n", x, ++d);
	printf("Approximate solution: x* = x%d = %.5f\n", d, x);
}
