#include <bits/stdc++.h>

using namespace std;

int bfs(string s, string t, map<string, vector<string> > g){
    queue<string> q;
    map<string, int> step;
    q.push(s);
    step[s] = 1;
    while (!q.empty()){
        string u = q.front();
        q.pop();
        if (u == t) return step[u]-1;
        for (int i = 0; i < g[u].size(); ++i){
            string v = g[u][i];
            if (!step[v]){
                q.push(v);
                step[v] = step[u] + 1;
            }
        }
    }
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    int T;
    cin >> T;
    while (T--){
        string s;
        map<string, vector<string> > g;
        while (cin >> s && s != "*"){
            g[s];
            for (map<string, vector<string> >::iterator it = g.begin(); it != g.end(); it++){
                string tmp = it->first;
                int n = s.length(), diff = 0;
                if (tmp.length() != n) continue;
                for (int i = 0; i < n && diff < 2; ++i){
                    if (s[i] != tmp[i]) ++diff;
                }

                if (diff == 1){
                    g[s].push_back(tmp);
                    g[tmp].push_back(s);
                }
            }
        }

        string line;
        getline(cin, line);
        getline(cin, line);
        while (line != ""){
            string source, target;
            int pos = line.find(" ");
            source = line.substr(0, pos);
            target = line.substr(pos+1, line.length());
            cout << source << " " << target << " " << bfs(source, target, g) << endl;
            getline(cin, line);
            //return 0;
        }
        if (T > 0) cout << endl;
    }

    return 0;
}
