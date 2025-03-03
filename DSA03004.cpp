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
        int a[n + 2];
        if (n % 2)
            a[0] = 0;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        sort(a + 1, a + n + 1);
        ll a1 = 0, a2 = 0;
        if (n % 2) {
            for (int i = 0; i <= n; i++) {
                if (i % 2 == 0)
                    a1 = a1 * 10 + a[i];
                else
                    a2 = a2 * 10 + a[i];
            }
        } else {
            for (int i = 1; i <= n; i++) {
                if (i % 2 == 0)
                    a1 = a1 * 10 + a[i];
                else
                    a2 = a2 * 10 + a[i];
            }
        }
        // cout << a1 << " " << a2 << "\n";
        cout << a1 + a2 << "\n";
    }
    return 0;
}
