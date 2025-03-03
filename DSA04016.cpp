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
        int m, n, k;
        cin >> m >> n >> k;
        vector<int> v;
        for (int i = 0; i < m; i++) {
            int x;
            cin >> x;
            v.push_back(x);
        }
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            v.push_back(x);
        }
        sort(v.begin(), v.end());
        cout << v[k - 1] << "\n";
    }

    return 0;
}
