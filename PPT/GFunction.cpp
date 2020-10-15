#include "GUtils.h"

typedef
	vector<double> GFunction;

GFunction makeFunction (int n, double* a){
	vector<double> result;
	for(int i = 0; i<n; ++i)	
		result.push_back (a[i]);
	return result;
}

void fHornerProcess (GFunction& f, int toDeg, double alpha) {
	if (f.size () == 0)
		return;
		
	double b = f[f.size ()-1];
	for(int i = (int) f.size ()-2; i >= toDeg; --i) {
		f[i] = b = b*alpha + f[i];
	}		
}

double fValueAt (GFunction f, double alpha) { 
	// change this method to calculate more complicated function
	// calculating value follows Horner method
	
	if (f.size () == 0)
		return 0;
	
	fHornerProcess (f, 0, alpha);
	return f[0];
}

ll factorial (int n) {
	ll result = 1;
	for (int i = 2; i<=n; ++i) result *= i;
	return result;
}

double fDerivationAt (GFunction f, int n, double alpha){ 
	
	if (n >= f.size ())
		return 0;
		
	for (int i = 0; i<=n; ++i) {
		fHornerProcess (f, i, alpha);
	}
	
	return factorial (n) * f[n];
}

int main () {
	GFunction f = {1, 2, 3};
	cout << fDerivationAt (f, 1, 1) << ' ';
	cout << (fValueAt (f, 1.1) - fValueAt (f, 1.05))/0.05;
}
