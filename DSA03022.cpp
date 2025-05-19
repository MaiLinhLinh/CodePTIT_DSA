#include <bits/stdc++.h>
using namespace std;
#ifdef MaiLinh
#include <debug.h>
#else
#define debug(...) 12
#endif
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    ll tich = a[1] * a[2];
    if (a[n - 1] * a[n] > tich)
        tich = a[n - 1] * a[n];
    if (a[1] * a[2] * a[n] > tich)
        tich = a[1] * a[2] * a[n];
    if (a[n - 2] * a[n - 1] * a[n] > tich)
        tich = a[n - 2] * a[n - 1] * a[n];

    cout << tich << "\n";
    return 0;
}
