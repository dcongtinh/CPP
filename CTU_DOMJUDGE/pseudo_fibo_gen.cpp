#include <bits/stdc++.h>
#include <dirent.h>
#include <sys/stat.h>

// limit
#define oo 1000000007
#define OO 10000000000000007LL
#define maxN 100005

// loop
#define fto(i, x, y) for (int i = (x); i <= (y); ++i)
#define fdto(i, x, y) for (int i = (x); i >= (y); --i)
#define ftoa(i, x, y, a) for (int i = (x); i <= (y); i += a)
#define fdtoa(i, x, y, a) for (int i = (x); i >= (y); i -= a)
#define ftoit(it, var) for (__typeof(var.begin()) it = var.begin(); it != var.end(); ++it)
#define fdtoit(rit, var) for (__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); ++rit)

// debug
#define bug1d(a, x, y)                    \
    {                                     \
        cout << #a << ": ";               \
        fto(_, x, y) cout << a[_] << ' '; \
        cout << endl;                     \
    }
#define bug2d(a, x, y, u, v)                     \
    {                                            \
        cout << #a << ": " << endl;              \
        fto(i, x, y)                             \
        {                                        \
            fto(j, u, v) cout << a[i][j] << ' '; \
            cout << endl;                        \
        };                                       \
        cout << endl;                            \
    }
#define bug(a) cout << #a << " = " << a << endl;
#define bug2(a, b)                    \
    cout << #a << " = " << a << "; "; \
    cout << #b << " = " << b << endl;
#define bug3(a, b, c)                 \
    cout << #a << " = " << a << "; "; \
    cout << #b << " = " << b << "; "; \
    cout << #c << " = " << c << endl;

// operation
#define mp make_pair
#define pb push_back
#define pf push_front
#define mt make_tuple

// structure
#define ii pair<int, int>
#define vi vector<int>
#define vll vector<ll>
#define vii vector<ii>
#define iii tuple<int, int, int>
#define iiii tuple<int, int, int, int>

// get value
#define FF first
#define SS second
#define get(x, a) get<(x)>(a)

// data type
#define ll long long
#define ull unsigned long long

// function
#define lb lower_bound
#define ub upper_bound

// const value
#define pi 3.14159265358979323846264338327950288419716939937510

// Random range [L, R]
inline int Rand(int l, int r)
{
    return l + rand() % (r - l + 1);
}

using namespace std;

const int Test = 10;
const string problem = "PSEUDO_FIBO";
string test, direction;

string IntToString(int n)
{
    ostringstream temp;
    temp << n;
    return temp.str();
}

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

int main()
{
    srand(time(NULL));

    fto(i, 1, Test)
    {
        direction = problem + "/test" + IntToString(i);

        string st = direction;
        char *folderName = new char[st.length() + 1];
        strcpy(folderName, st.c_str());
        mkdir(folderName, 0777);

        string st_fi = direction + "/" + problem + ".inp";
        string st_fo = direction + "/" + problem + ".out";

        char *fileInput = new char[st_fi.length() + 1];
        char *fileOutput = new char[st_fo.length() + 1];

        strcpy(fileInput, st_fi.c_str());
        strcpy(fileOutput, st_fo.c_str());

        freopen(fileInput, "w", stdout); // Tao file input

        // code here
        int a = Rand(0, 100);
        int b = Rand(0, 100);
        int n = Rand(0, 1000000000);
        int m = Rand(1, 4);
        cout << a << " " << b << " ";
        cout << n << " " << m;
        freopen(fileOutput, "w", stdout); // Tao file output
        A.mat[1][1] = 0; A.mat[1][2] = 1;
        A.mat[2][1] = 1; A.mat[2][2] = 1;
 
        F.mat[1][1] = a;
        F.mat[2][1] = b;
        int mod = 1;
        fto(i, 1, m) mod *= 10;
 
        matrix ans = mul_mat(F, pow_mat(n-1, mod), mod);
        cout << ans.mat[2][1];
        // print result
    }

    return 0;
}
