#include <bits/stdc++.h>

using namespace std;

map<string, int> m;
map<int, string> rm;
int trace[1000000];
vector<int> ke[1000000];

void bfs(int s){
    queue<int> q;
    q.push(s);
    trace[s] = s;
    while (!q.empty()){
        int u = q.front();q.pop();
        for (vector<int>::iterator it = ke[u].begin(); it != ke[u].end(); it++){
            int v = (*it);
            if (!trace[v]){
                q.push(v);
                trace[v] = u;
            }
        }
    }
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    int k;
    bool firstline = true;
    while (scanf("%d", &k) != EOF){
        if (firstline) firstline = false;
        else printf("\n");
        m.clear(); rm.clear();
        string x, y, tmp;
        getline(cin, tmp);
        int n = 0;
        for (int i = 0; i < k; ++i){
            cin >> x >> y;
            getline(cin, tmp);
            if (!m[x]){
                m[x] = ++n;
                rm[n] = x;
            }

            if (!m[y]){
                m[y] = ++n;
                rm[n] = y;
            }
            ke[m[x]].push_back(m[y]);
            ke[m[y]].push_back(m[x]);
        }

        for (int i = 0; i <= n; ++i) trace[i] = 0;
        cin >> y >> x;
        bfs(m[x]);
        for (int i = 0; i <= n; ++i) ke[i].clear();
        if (!trace[m[y]]){
            printf("No route\n");
        } else{
            int s = m[x], t = m[y];
            int u = s;
            while (u!=t){
                cout << rm[t] << " " << rm[trace[t]] << endl;
                t = trace[t];
            }
        }
    }
    return 0;
}
