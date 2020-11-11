#include <bits/stdc++.h>
#define fto(i, x, y) for (int i=(x); i <= (y); ++i)
#define fdto(i, x, y) for (int i=(x); i >= (y); --i)
#define forit(it, var) for (__typeof(var.begin()) it = var.begin(); it != var.end(); ++it)
#define forrit(it, var) for (__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); ++rit)
#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define vi vector<int>
#define fi first
#define se second
#define ll long long
#define oo 1000000007
#define maxN 100005
 
using namespace std;
 
struct matrix{
    int mat[3][3];
} A, F;
 
matrix mul_mat(const matrix &F, const matrix &A, int mod){
    matrix C;
    fto(i, 1, 2){
        fto(j, 1, 2){
            C.mat[i][j] = 0;
        }
    }
    fto(i, 1, 2){
        fto(j, 1, 2){
            fto(k, 1, 2){
                C.mat[i][k] += (A.mat[i][j]*F.mat[j][k])%mod;
                C.mat[i][k] %= mod;
            }
        }
    }
    return C;
}
 
matrix pow_mat(int n, int mod){
    if (n == 1) return A;
    matrix tmp = pow_mat(n/2, mod);
    tmp = mul_mat(tmp, tmp, mod);
    if (n%2) return mul_mat(tmp, A, mod);
    return tmp;
 
}
 
int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int a, b, n, m;
    scanf("%d%d%d%d", &a, &b, &n, &m);
    A.mat[1][1] = 0; A.mat[1][2] = 1;
    A.mat[2][1] = 1; A.mat[2][2] = 1;

    F.mat[1][1] = a;
    F.mat[2][1] = b;
    int mod = 1;
    fto(i, 1, m) mod *= 10;

    matrix ans = mul_mat(F, pow_mat(n-1, mod), mod);
    cout << ans.mat[2][1];
    
 
    return 0;
}