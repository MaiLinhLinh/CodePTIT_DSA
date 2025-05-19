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
int n, a[100005];

ll f[nmax] = { 0 };
void calc()
{
    f[0] = 0;
    for (int i = 1; i <= n; i++) {
        f[i] = f[i - 1];
        if (a[i] > 0)
            f[i] += a[i];
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    calc();
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << f[r] - f[l - 1] << "\n";
    }

    return 0;
}
