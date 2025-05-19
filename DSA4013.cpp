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
        int a[n + 1];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n);
        int ans = n, l = n / 2 - 1, r = n - 1;
        while (l >= 0 && r >= n / 2) {
            if (2 * a[l] <= a[r]) {
                l--;
                r--;
                ans--;
            } else
                l--;
        }
        cout << ans << "\n";
    }

    return 0;
}
