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
        vector<int> v;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            v.push_back(a[i]);
        }
        for (int i = 0; i < m; i++) {
            cin >> b[i];
            v.push_back(b[i]);
        }
        sort(v.begin(), v.end());
        for (auto x : v)
            cout << x << " ";
        cout << "\n";
    }

    return 0;
}
