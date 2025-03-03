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
int n, s, k;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> s >> k;
        int a[n + 1];
        ll f[n + 2];
        f[0] = 0;
        for (int i = 1; i <= n; i++)
            cin >> a[i];

        f[1] = a[1];
        for (int i = 2; i <= n; i++)
            f[i] = f[i - 1] + a[i];

        int ans = -1;
        for (int i = 1; i <= s; i++) {
            if (f[s] - f[i - 1] <= k) {
                ans = i;
                break;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
