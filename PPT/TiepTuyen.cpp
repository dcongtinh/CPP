/* Tinh */

#include "GFunction.h"

#define EPS 1e-5
#define sqr(x) (x) * (x)

using namespace std;

int main()
{
    GFunction f = inputFunction();
    double a = toNum<double>(input("from  a = "));
    double b = toNum<double>(input("to    b = "));
    double M1, M2, esp, pivot, fpivot;

    M1 = max(abs(fDerivationAt(f, 2, a)), abs(fDerivationAt(f, 2, b)));
    M2 = min(abs(fDerivationAt(f, 1, a)), abs(fDerivationAt(f, 1, b)));

    esp = toNum<double>(input("epsilon = "));

    double x0 = 0.0, x = 0.0;
    if (fDerivationAt(f, 0, a) < 0 && fDerivationAt(f, 1, a) > 0 && fDerivationAt(f, 2, a) < 0)
        x0 = a;
    else if (fDerivationAt(f, 0, a) > 0 && fDerivationAt(f, 1, a) < 0 && fDerivationAt(f, 2, a) > 0)
        x0 = a;
    else if (fDerivationAt(f, 0, b) > 0 && fDerivationAt(f, 1, b) > 0 && fDerivationAt(f, 2, b) < 0)
        x0 = b;
    else
        x0 = b;
    x = x0 - fDerivationAt(f, 0, x0) * 1.0 / fDerivationAt(f, 1, x0);
    int d = 0;
    while ((double)sqr(x - x0) * M1 * 1.0 / (2.0 * M2) > esp)
    {
        printf("%.5f   (|x%d - x*| > epsilon)\n", x, ++d);
        x0 = x;
        x = x0 - fDerivationAt(f, 0, x0) * 1.0 / fDerivationAt(f, 1, x0);
    }
    printf("%#.5f   (|x%d - x*| < epsilon)\n", x, ++d);
    printf("Approximate solution: x* = x%d = %.5f\n", d, x);
}
