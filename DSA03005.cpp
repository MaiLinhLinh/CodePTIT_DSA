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
        int n, k;
        cin >> n >> k;
        if (k > n - k)
            k = n - k;
        ll a[n + 2];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n);
        ll sum1 = 0, sum2 = 0;
        for (int i = 0; i < k; i++)
            sum1 += a[i];
        for (int i = k; i < n; i++)
            sum2 += a[i];
        cout << sum2 - sum1 << '\n';
    }
    return 0;
}
