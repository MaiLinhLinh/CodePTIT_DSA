#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;
int count(int x, int y[], int m)
{
    if (x == 0 || x == 1)
        return 0;
    int res = 0;
    int pos = upper_bound(y, y + m, x) - y;
    res += (m - pos);
    if (x == 2) {
        int l = lower_bound(y, y + m, 3) - y;
        int r = upper_bound(y, y + m, 3) - y;
        res -= (r - l);
        l = lower_bound(y, y + m, 4) - y;
        r = upper_bound(y, y + m, 4) - y;
        res -= (r - l);
    }
    if (x == 3) {
        int l = lower_bound(y, y + m, 2) - y;
        int r = upper_bound(y, y + m, 2) - y;
        res += (r - l);
    }
    return res;
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
        int x[n + 2], y[m + 2];

        int dem1x = 0;
        int dem0x = 0;
        for (int i = 0; i < n; i++) {
            cin >> x[i];
            if (x[i] == 1)
                dem1x++;
            else if (x[i] == 0)
                dem0x++;
        }

        int dem1y = 0;
        int dem0y = 0;
        for (int i = 0; i < m; i++) {
            cin >> y[i];
            if (y[i] == 1)
                dem1y++;
            else if (y[i] == 0)
                dem0y++;
        }

        sort(y, y + m);

        int ans = 0;
        if (dem1y)
            ans += dem1y * (n - dem1x - dem0x);

        if (dem0y)
            ans += dem0y * (n - dem0x);

        for (int i = 0; i < n; i++) {
            ans += count(x[i], y, m);
        }
        cout << ans << "\n";
    }

    return 0;
}
