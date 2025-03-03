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
        priority_queue<int, vector<int>, greater<int>> qu;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            qu.push(a[i]);
        }
        ll ans = 0;
        while (qu.size() != 1) {
            ll x = 0;
            x += (ll)qu.top();
            // cout << x << "\n";
            qu.pop();
            x += (ll)qu.top();
            qu.pop();
            // cout << x << "\n";
            ans += x;
            qu.push(x);
        }
        cout << ans << "\n";
    }
    return 0;
}
