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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        ll a[n + 1];
        ll b[n + 1];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            b[i] = a[i];
        }
        sort(b, b + n);
        int pos = lower_bound(b, b + n, a[0]) - b;
        debug(pos);
        int ans = n - pos;
        int dem = 0;
        for (int i = 1; i < n; i++) {
            if (a[i] == a[0])
                dem++;
            else
                dem = 0;
        }
        ans = ans - dem;
        if (ans == n)
            ans = 0;
        cout << ans << "\n";
    }

    return 0;
}
