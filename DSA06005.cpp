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
        int n, m;
        cin >> n >> m;
        int a[n + 1], b[m + 1];
        set<int> se;
        map<int, int> mp;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            se.insert(a[i]);
            mp[a[i]] = 1;
        }
        for (int i = 0; i < m; i++) {
            cin >> b[i];
            se.insert(b[i]);
            if (mp[b[i]] == 1)
                mp[b[i]] = 2;
        }
        for (auto x : se)
            cout << x << " ";
        cout << "\n";
        for (auto x : mp) {
            if (x.second == 2)
                cout << x.first << " ";
        }
        cout << "\n";
    }

    return 0;
}
