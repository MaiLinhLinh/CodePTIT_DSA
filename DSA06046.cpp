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
        int n;
        cin >> n;
        int a[n + 1];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int ans = 1e10;
        sort(a, a + n);
        for (int i = 1; i < n; i++) {
            ans = min(ans, a[i] - a[i - 1]);
            if (ans == 0)
                break;
        }
        cout << ans << "\n";
    }

    return 0;
}
