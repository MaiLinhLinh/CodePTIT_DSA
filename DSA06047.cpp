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
        ll a[n + 1];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            a[i] *= a[i];
        }
        sort(a, a + n);
        bool check = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                int pos = lower_bound(a + j + 1, a + n, a[i] + a[j]) - a;
                if (pos < n && a[pos] == a[i] + a[j]) {
                    check = 1;
                    cout << "YES\n";
                    break;
                }
            }
            if (check == 1)
                break;
        }
        if (check == 0)
            cout << "NO\n";
    }

    return 0;
}
