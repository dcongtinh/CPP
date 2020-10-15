#include <bits/stdc++.h>

using namespace std;

vector<string> dd[300];
int dem[300];
map<string, int> b;
bool visit[300][1000][1000];

int bfs(string s, string t){
    queue<string> q;
    map<string, int> d;

    q.push(s);

    int m = s.length();
    while (!q.empty()){
        string s1 = q.front();
        q.pop();
        int n = dd[m].size();
        for (int i = 0; i < n; ++i){
            string s2 = dd[m][i];
            if (visit[m][b[s1]][b[s2]] && s1!=s2){
                q.push(s2);
                d[s2] = d[s1] + 1;
                if (s2 == t) return d[s2];
                visit[m][b[s1]][b[s2]] = false;
            }
        }
    }
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    int T;
    scanf("%d", &T);
    while (T--){
        string s;
        memset(dem, 0, sizeof(dem));
        memset(visit, false, sizeof(visit));
        b.clear();
        for (int i = 0; i <= 300; ++i) dd[i].clear();
        while (cin >> s && s != "*"){
            int m = s.length();
            dd[m].push_back(s);
            b[s]=++dem[m];
        }

        for (int i = 1; i <= 10; ++i){

            int m = dd[i].size();
            for (int j = 0; j < m-1; ++j){
                for (int k = j+1; k < m; ++k){
                    string s1 = dd[i][j], s2 = dd[i][k];
                    //cout << s1 << " " << s2 << endl;
                    int n = s1.length();
                    int d = 0;
                    for (int p = 0; p < n; ++p){
                        if (s1[p]==s2[p]) ++d;
                        //cout << s1[p];
                    }
                    //cout << d << n;

                    if (d == n-1){
                        //cout << b[s1] << b[s2];
                        visit[n][b[s1]][b[s2]] = true;
                        visit[n][b[s2]][b[s1]] = true;
                    }
                }
            }
        }

        /**for (int i = 1; i <= 10; ++i){
            cout << i << ": ";
            int m = dd[i].size();
            for (int j = 0; j < m-1; ++j){
                for (int k = j+1; k < m; ++k){
                    int n = dd[i][j].length();
                    cout << visit[n][b[dd[i][j]]][b[dd[i][k]]] << " ";

                }
            }
            cout << endl;
        }**/

        getline(cin, s);

        while (getline(cin, s)){
            if (s.length() == 0) break;
            string a = "", b="";
            int m = s.length()/2;
            for (int i = 0; i < m; ++i) a+=s[i], b+=s[i+m+1];
            cout << a << " " << b << " ";
            printf("%d\n",bfs(a, b));
        }
        if (T!=0) printf("\n");
    }
    return 0;
}
