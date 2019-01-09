#include <stdio.h>
#include <iostream>

#include "D:\\lib\alistlib.h"

using namespace std;

int tangdan(List L){
    Position P = First(L);
    ElementType T = Retrieve(P, L);
    if ('a' <= T && T <= 'z') T -= 32;
    P = Next(P, L);
	while (P != EndList(L)){
	    ElementType N = Retrieve(P, L);
        if ('a' <= N && N <= 'z') N -= 32;
        if (T > N) return 0;
        T = N;
		P=Next(P,L);
	}
    return 1;
}

int XoaPhuAm(List *L){
    Position P = First(*L);
	while (P != EndList(*L)){
	    ElementType N = Retrieve(P, *L);
        if ('a' <= N && N <= 'z') N -= 32;
        if (N != 'A' && N != 'O' && N != 'E' && N != 'U' && N != 'I') {
            Delete_List(P, L);
            XoaPhuAm(L);
        } else P=Next(P, *L);
	}
}

int main(){
    List L;
    MakeNull_List(&L);
    printf("Nhap so phan tu: ");
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        char c;
        printf("Nhap ki tu thu %d: ", i);
        cin >> c;
        Insert_List(c, i, &L);
    }
    printf("Day vua nhap:\n");
    Print_List(L);
    if (tangdan(L)) printf("Day tang dan !!!\n");
    else printf("Day khong tang dan!!!\n");
    XoaPhuAm(&L);
    printf("Day da xoa phu am:\n");
    Print_List(L);
	return 0;
}
















