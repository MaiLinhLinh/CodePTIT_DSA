#include <bits/stdc++.h>
using namespace std;
#ifdef MaiLinh
#include <debug.h>
#else
#define debug(...) 12
#endif
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e18 + 7)
int n;
ll a[20], c[20][20];
ll ans = nmax, cmin = nmax;
bool visited[25];

void Try(int i, ll chiphi)
{
    for (int j = 2; j <= n; j++) {
        if (!visited[j]) {
            a[i] = j;
            visited[j] = 1;
            chiphi += c[a[i - 1]][a[i]];
            if (i == n) {
                ans = min(ans, chiphi + c[a[n]][1]);
            } else if (chiphi + cmin * (n - i + 1) <= ans)
                Try(i + 1, chiphi);
            visited[j] = 0;
            chiphi -= c[a[i - 1]][a[i]];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> c[i][j];
            if (c[i][j] != 0)
                cmin = min(cmin, c[i][j]);
        }
    }
    if (n == 1) {
        cout << "0\n";
    } else {
        a[1] = 1;
        Try(2, 0);
        cout << ans << "\n";
    }

    return 0;
}
