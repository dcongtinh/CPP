#include <stdio.h>
#include <iostream>

#include "\\vmware-host\Shared Folders\Desktop\C++\lib\bstlib.h"
using namespace std;

int main(){
	FILE *fi, *fo;

    fi = fopen("input.txt", "r");
    fo = fopen("output.txt", "w");
    int n, a[10];
    fscanf(fi, "%d", &n);

    for (int i = 1; i <= n; ++i) fscanf(fi, "%d", &a[i]);
//    fclose(fi);
    for (int i = 1; i <= n; ++i) fprintf(fo, "%d", a[i]);
	return 0;
}















