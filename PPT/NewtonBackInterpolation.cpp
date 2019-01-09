/* Phuc */

#include "GFunction.h"

GFunction mulWithAlpha(GFunction f, double alpha)
{
	for (int i = 0; i < f.size(); ++i)
		f[i] *= alpha;
	return f;
}

GFunction addFunction(GFunction f, GFunction g)
{
	GFunction result;
	int i;
	for (i = 0; i < f.size() && i < g.size(); ++i)
	{
		result.push_back(f[i] + g[i]);
		//		cout << f[i] + g[i] << ' ';
	}
	//cout << endl;
	for (; i < f.size(); ++i)
		result.push_back(f[i]);
	for (; i < g.size(); ++i)
		result.push_back(g[i]);

	for (; result[result.size() - 1] == 0;)
	{
		result.pop_back();
	}

	return result;
}
GFunction mulFunction(GFunction f, GFunction g)
{
	vector<double> result(f.size() + g.size(), 0);

	for (int i = 0; i < f.size(); ++i)
		for (int j = 0; j < g.size(); ++j)
			result[i + j] = result[i + j] + f[i] * g[j];

	for (; result[result.size() - 1] == 0;)
	{
		result.pop_back();
	}
	return result;
}

GFunction newton(vector<double> x, vector<double> y)
{ // x.size () == y.size ()

	vector<vector<double>> a;
	a.resize(x.size());
	//cout << a.size () << endl;
	for (int i = 0; i < x.size(); ++i)
		a[i].resize(x.size());

	for (int i = 0; i < x.size(); ++i)
	{
		a[i][0] = y[i];
	}

	for (int i = x.size() - 2; i >= 0; --i)
		for (int j = 0; j <= i; ++j)
		{
			int id = x.size() - i - 1;
			a[j][id] =
				(a[j + 1][id - 1] - a[j][id - 1]);
			a[j][id] /= (x[j + id] - x[j]);
		}
	// for (int i = 0; i < x.size(); ++i)
	// {
	// 	for (int j = 0; j < x.size(); ++j)
	// 		cout << a[i][j] << " ";
	// 	cout << endl;
	// }
	GFunction result, pol = {1};
	for (int i = x.size() - 1; i >= 0; --i)
	{
		result = addFunction(result, mulWithAlpha(pol, a[i][x.size() - i - 1]));
		pol = mulFunction(pol, {-x[i], 1});
	}
	cout << endl;

	return result;
}

int main()
{
	int n = toNum<int>(input("Input n = "));
	vector<double> arr_x, arr_y;

	for (int i = 0; i <= n; ++i)
	{
		int x = toNum<int>(input("x [" + toString(i) + "] = "));
		int y = toNum<int>(input("y [" + toString(i) + "] = "));
		arr_x.push_back(x);
		arr_y.push_back(y);
	}
	cout << endl;
	print(newton(arr_x, arr_y));
}
