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
        ll a[n + 1], b[n + 1];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        ll tmp = 1e12;
        ll res;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (abs(a[i] + a[j]) < tmp) {
                    tmp = abs(a[i] + a[j]);
                    res = a[i] + a[j];
                }
            }
        }
        cout << res << "\n";
    }

    return 0;
}
