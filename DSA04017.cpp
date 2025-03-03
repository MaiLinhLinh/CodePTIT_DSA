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
        int a[n + 1], b[n + 1];
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i < n; i++) {
            cin >> b[i];
        }

        int l = 1, k = 1;
        int ans;
        while (l <= n && k < n) {
            if (a[l] == b[k]) {
                l++;
                k++;
            } else {
                ans = k;
                l++;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
