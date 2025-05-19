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

int n, k, ok;
int a[20], b[20];
vector<vector<int>> ans;

void sinh()
{
    int i = n;
    while (i >= 1 && a[i] == 1) {
        a[i] = 0;
        i--;
    }
    if (i == 0)
        ok = 0;
    else
        a[i] = 1;
}

bool check()
{
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == 1)
            cnt++;
    }
    return cnt == k;
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
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
            cin >> b[i];
        sort(b + 1, b + n + 1);
        for (int i = 1; i <= n; i++)
            a[i] = 0;
        ok = 1;
        while (ok) {
            if (check()) {
                vector<int> tmp;
                for (int i = 1; i <= n; i++) {
                    if (a[i] == 1)
                        tmp.push_back(b[i]);
                }
                ans.push_back(tmp);
            }
            sinh();
        }
        sort(ans.begin(), ans.end());
        for (int i = 0; i < ans.size(); i++) {
            for (int j = 0; j < ans[i].size(); j++)
                cout << ans[i][j] << " ";
            cout << '\n';
        }
    }

    return 0;
}
