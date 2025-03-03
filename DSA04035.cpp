#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;

ll binpow(ll a, ll b)
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
    ll a, b;
    while (cin >> a >> b) {
        if (a == 0 && b == 0)
            break;
        cout << binpow(a, b) << "\n";
    }

    return 0;
}
