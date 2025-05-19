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
    int f[n + 1] = { 0 };
    int s = 0;
    for (int i = 1; i <= n; i++) {
        f[a[i]] = f[a[i] - 1] + 1;
        s = max(s, f[a[i]]);
    }
    cout << n - s << '\n';

    return 0;
}
