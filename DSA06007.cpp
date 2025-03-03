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
        int a[n + 1], b[n + 1];
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            b[i] = a[i];
        }
        sort(b + 1, b + n + 1);
        int l = 0, r = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] != b[i]) {
                l = i;
                break;
            }
        }
        for (int i = n; i >= 1; i--) {
            if (a[i] != b[i]) {
                r = i;
                break;
            }
        }
        cout << l << " " << r << "\n";
    }

    return 0;
}
