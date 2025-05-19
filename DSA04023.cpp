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
        int n, k;
        cin >> n >> k;
        int a[n + 1];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n);
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            int x = a[i] + k;
            int pos = lower_bound(a + i + 1, a + n, x) - a;

            ans += (pos - i - 1);
        }
        cout << ans << "\n";
    }

    return 0;
}
