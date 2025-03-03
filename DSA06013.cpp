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
        int n, x;
        cin >> n >> x;
        int a[n + 1];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int ans = upper_bound(a, a + n, x) - lower_bound(a, a + n, x);
        if (ans == 0)
            ans = -1;
        cout << ans << "\n";
    }

    return 0;
}
