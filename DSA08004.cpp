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
        int k;
        cin >> k;
        string s;
        cin >> s;
        map<char, int> mp;
        for (int i = 0; i < s.size(); i++) {
            mp[s[i]]++;
        }
        priority_queue<ll> pq;

        for (auto x : mp) {
            pq.push(x.second);
        }
        while (k-- && !pq.empty()) {
            ll x = pq.top();
            pq.pop();
            if (x > 1)
                pq.push(x - 1);
        }

        ll ans = 0;
        while (!pq.empty()) {
            ll x = pq.top();
            ans += x * x;
            pq.pop();
        }
        cout << ans << "\n";
    }

    return 0;
}
