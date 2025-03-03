#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;

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
        ll a[n + 1];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n);
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] >= k)
                break;
            for (int j = i + 1; j < n; j++) {
                if (a[i] + a[j] >= k)
                    break;
                ll x = k - (a[i] + a[j]);
                ans += lower_bound(a + j + 1, a + n, x) - a - j - 1;
            }
        }
        cout << ans << "\n";
    }

    return 0;
}
