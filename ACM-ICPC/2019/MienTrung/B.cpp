#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    cin >> T;
    multiset<pair<int, int>> ms;

    while (T--)
    {
        int d, t;
        scanf("%d%d", &d, &t);
        ms.insert({d, t});
        int time = 0, ans = 0;
        for (auto it : ms)
        {
            time += it.second;
            ans = max(ans, max(0, time - it.first));
        }
        printf("%d\n", ans);
    }
}