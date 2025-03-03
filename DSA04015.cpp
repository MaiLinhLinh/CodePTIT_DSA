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
        int x;
        cin >> x;
        ll a[n + 2];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int pos = upper_bound(a, a + n, x) - a;
        if (pos == 0)
            pos = -1;
        cout << pos << "\n";
    }

    return 0;
}
