#include <bits/stdc++.h>
using namespace std;
#ifdef MaiLinh
#include <debug.h>
#else
#define debug(...) 12
#endif
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(5e3 + 7)
int w[5005], v[5005];
// f[i][j] la gia tri lon nhat cua tui co khoi luong j khi dung i do vat,
ll calc(int n, int m)
{
    vector<vector<int>> f(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {

        for (int j = m; j > 0; j--) {
            if (j < w[i])
                f[i][j] = f[i - 1][j];
            else
                f[i][j] = max(f[i - 1][j - w[i]] + v[i], f[i - 1][j]);
        }
    }
    return f[n][m];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            cin >> w[i];
        }
        for (int i = 1; i <= n; i++) {
            cin >> v[i];
        }
        ll ans = calc(n, m);
        cout << ans << "\n";
    }

    return 0;
}
