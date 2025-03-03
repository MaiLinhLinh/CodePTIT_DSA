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
        map<int, int> mp;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            mp[a[i]]++;
        }
        sort(a, a + n);
        int ans = 0;
        for (int i = a[0]; i <= a[n - 1]; i++) {
            if (!mp.count(i))
                ans++;
        }
        cout << ans << "\n";
    }

    return 0;
}
