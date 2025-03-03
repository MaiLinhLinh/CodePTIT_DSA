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
int n, ok;
int a[15][15];

void Try(int x, int y, string ans)
{
    if (x == n - 1 && y == n - 1) {
        ok = 1;
        cout << ans << " ";
    } else if ((x + 1 < n) && a[x + 1][y] == 1)
        Try(x + 1, y, ans + "D");
    else if ((y + 1 < n) && a[x][y + 1] == 1)
        Try(x, y + 1, ans + "R");
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        ok = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cin >> a[i][j];
        }
        Try(0, 0, "");
        if (ok == 0)
            cout << "-1";
        cout << "\n";
    }
    return 0;
}
