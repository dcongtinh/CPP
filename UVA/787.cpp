#include <bits/stdc++.h>
#define fto(i,x,y) for (int i = (x); i <= (y); ++i)
#define fdto(i,x,y) for (int i = (x); i >= (y); --i)
#define ms(a, x) memset(a, x, sizeof a)
#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define fi first
#define se second
#define ll long long
#define oo 1000000007
#define maxN 200005
using namespace std;

vector<int> a, ans, res, b;
int am;

void nhan(int x){
    if (x < 0) ++am, x=-x;
    int m = res.size();
    int tmp=0;
    b.clear();
    fto(i,0,m-1){
        b.pb((x*res[i] + tmp)%10);
        tmp = (x*res[i] + tmp)/10;
    }
    while(tmp > 0) b.pb(tmp%10), tmp/=10;
    res.clear();
    fto(i,0,b.size()-1) res.pb(b[i]);
}

bool ss(vector<int> res, vector<int> ans){
    int m = res.size(), n = ans.size();
    if (res[m-1] > 0 && ans[n-1] < 0) return true;
    if (res[m-1] < 0 && ans[n-1] > 0) return false;
    if (res[m-1] > 0 && ans[n-1] > 0){
        if (m > n) return true;
        if (m < n) return false;
        fdto(i,m-1,0){
            if (res[i] > ans[i]) return true;
            if (res[i] < ans[i]) return false;
        }
        return false;
    }
    if (m < n) return true;
    if (m > n) return false;
    res[m-1]*=-1;
    ans[n-1]*=-1;
    fto(i,m-1,0){
        if (res[i] < ans[i]) return true;
        if (res[i] > ans[i]) return false;
    }

    return false;
}

void solve(int n){
    fto(i,0,n-1)
        fto(j,i,n-1){
            res.clear();
            res.pb(1);
            am=0;
            fto(p,i,j) nhan(a[p]);
            if (am%2) res[res.size()-1]*=-1;
            if (ss(res, ans)){
                ans.clear();
                fto(p,0,res.size()-1) ans.pb(res[p]);
            }
    }
    fdto(i,ans.size()-1,0) cout << ans[i];
    cout << endl;
}

int main(){
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int x;
    while (scanf("%d", &x)!=EOF){
        a.clear();
        a.pb(x);
        while (scanf("%d", &x) && x!=-999999) a.pb(x);
        fto(i,0,10000) ans.pb(0);
        ans[10000-1]*=-1;
        solve(a.size());
    }
    return 0;
}
