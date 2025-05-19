#include <bits/stdc++.h>
using namespace std;
#ifdef MaiLinh
#include <debug.h>
#else
#define debug(...) 12
#endif
#define ll long long
#define mod 123456789
#define nmax int(1e6 + 7)

ll binpow(int a, ll b)
{
    if (b == 0)
        return 1;
    ll x = binpow(a, b / 2);
    if (b % 2)
        return ((x % mod * x % mod) % mod * a % mod) % mod;
    return (x % mod * x % mod) % mod;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        cout << binpow(2, n - 1) << "\n";
    }

    return 0;
}
