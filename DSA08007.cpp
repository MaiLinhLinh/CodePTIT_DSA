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
        ll n;
        cin >> n;
        queue<ll> q;
        q.push(1);
        int cnt = 0;
        while (!q.empty()) {
            ll x = q.front();
            // cout << x << "\n";
            q.pop();
            cnt++;
            if (x * 10 <= n)
                q.push(x * 10);
            if (x * 10 + 1 <= n)
                q.push(x * 10 + 1);
        }
        cout << cnt << "\n";
    }

    return 0;
}
