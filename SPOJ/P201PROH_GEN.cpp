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
const string problem = "BIENDOI";
string test, direction;

string IntToString(int n)
{
    ostringstream temp;
    temp << n;
    return temp.str();
}

string solve(ll a, ll b)
{
    if (a >= b)
        return "YES";
    if (a % 2 == 0 && 3 * a / 2 > a)
        return "YES";
    if (a % 2 == 1 && 3 * (a - 1) / 2 > a)
        return "YES";
    return "NO";
}

int main()
{
    srand(time(NULL));

    fto(i, 2, Test)
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
        int T = Rand(1, 10000);
        cout << T << endl;
        vector<ii> v;
        fto(i, 1, T)
        {
            int a = Rand(1, 1000000000);
            int b = Rand(1, 1000000000);
            if (T % 2 == 0)
                a = Rand(1, 3);
            cout << a << " " << b << endl;
            v.push_back({a, b});
        }

        freopen(fileOutput, "w", stdout); // Tao file output
        for (auto p : v)
            cout << solve((ll)p.first, (ll)p.second) << endl;
        // print result
    }

    return 0;
}
