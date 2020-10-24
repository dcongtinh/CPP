#include <bits/stdc++.h>

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

const int Test = 1;
const string problem = ""; // name problem here
string test, direction;

string IntToString(int n)
{
    ostringstream temp;
    temp << n;
    return temp.str();
}

int main()
{
    srand(time(NULL));
    fto(i, 1, Test)
    {
        direction = problem + "/test" + IntToString(i);
        string st = "mkdir -p " + direction;
        system(st.c_str());

        string fileInput = direction + "/" + problem + ".inp";
        string fileOutput = direction + "/" + problem + ".out";

        freopen(fileInput.c_str(), "w", stdout); // Tao file input

        // code here

        freopen(fileOutput.c_str(), "w", stdout); // Tao file output

        // print result
    }

    return 0;
}
