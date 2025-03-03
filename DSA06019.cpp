#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;

bool cmp(pair<int, int> p, pair<int, int> q)
{
    if (p.second == q.second)
        return p.first < q.first;
    return p.second > q.second;
}

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
        map<int, int> mp;
        int a[n + 2];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            mp[a[i]]++;
        }
        pair<int, int> pii[n + 2];
        int d = 0;
        for (auto x : mp) {
            pii[d++] = { x.first, x.second };
        }
        sort(pii, pii + d, cmp);
        for (auto x : pii) {
            while (x.second != 0) {
                cout << x.first << " ";
                x.second--;
            }
        }

        cout << "\n";
    }
    return 0;
}
