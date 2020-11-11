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
const string problem = "DISTANCE";
string test, direction;

string IntToString(int n)
{
    ostringstream temp;
    temp << n;
    return temp.str();
}
int n, d;
int a[maxN];
pair<int, int> f[maxN];

void UPDATE(int x, int val)
{
    while (x <= n)
    {
        f[x].first = max(f[x].first, val);
        f[x].second = min(f[x].second, val);
        x += x & (-x);
    }
}

int GET(int l, int r)
{
    int mx = 0, mn = oo;
    while (r >= l)
    {
        if (r - (r & (-r)) >= l)
        {
            mx = max(mx, f[r].first);
            mn = min(mn, f[r].second);
            r -= r & (-r);
        }
        else
        {
            mx = max(mx, a[r]);
            mn = min(mn, a[r]);
            --r;
        }
    }
    return mx - mn;
}

int main()
{
    srand(time(NULL));

    fto(i, 3, Test)
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
        n = Rand(2, 100000), d = Rand(1, n);
        cout << n << " " << d << endl;
        for (int i = 1; i <= n; ++i)
        {
            f[i].first = 0;
            f[i].second = oo;
        }
        int ans = 0;
        for (int i = 1; i <= n; ++i)
        {
            int x = Rand(0, 1000000000);
            a[i] = x;
            cout << x << " ";
            UPDATE(i, x);
            int diff = GET(max(i - d + 1, 1), i);
            ans = max(ans, diff);
        }
        freopen(fileOutput, "w", stdout); // Tao file output
        cout << ans;
        // print result
    }

    return 0;
}
