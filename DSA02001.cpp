#include <bits/stdc++.h>
using namespace std;
#ifdef MaiLinh
#include <debug.h>
#else
#define debug(...) 12
#endif
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
int n;
int a[20];
vector<vector<int>> ans;
void solve()
{
    cin >> n;
    vector<int> tmp;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        tmp.push_back(a[i]);
    }
    ans.push_back(tmp);
    while (tmp.size() >= 2) {
        int m = tmp.size() - 1;
        for (int i = 1; i < tmp.size(); i++)
            a[i] = tmp[i - 1] + tmp[i];
        tmp.clear();
        for (int i = 1; i <= m; i++)
            tmp.push_back(a[i]);
        ans.push_back(tmp);
    }
    for (int i = 0; i < ans.size(); i++) {
        cout << "[";
        for (int j = 0; j < ans[i].size() - 1; j++)
            cout << ans[i][j] << " ";
        cout << ans[i][ans[i].size() - 1] << "]\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        ans.clear();
        solve();
    }

    return 0;
}
