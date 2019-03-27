#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    long long sum = (long long)n * (n + 1) / 2;
    cout << sum % 2 << endl;
    sum /= 2;
    vector<int> ans;
    for (int i = n; i > 0; --i)
    {
        if (sum >= i)
        {
            sum -= i;
            ans.push_back(i);
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << " ";
    for (auto it : ans)
        cout << it << " ";
}