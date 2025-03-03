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
        int a[n + 2];
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        int tmp = 0, ans = -1e5;
        for (int i = 1; i <= n; i++) {
            tmp += a[i];
            ans = max(ans, tmp);
            if (tmp < 0)
                tmp = 0;
        }
        cout << ans << "\n";
    }

    return 0;
}
