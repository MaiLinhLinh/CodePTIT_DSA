#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;
ll luythua(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll x = luythua(a, b / 2);
    if (b % 2)
        return ((x % mod * x % mod) % mod * a % mod) % mod;
    else
        return (x % mod * x % mod) % mod;
}
// code khử đệ quy
ll binpow(ll a, ll b)
{
    ll res = 1;
    while (b > 0) {
        if (b % 2)
            res = (res * a % mod) % mod;
        a = a * a % mod;
        b /= 2;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        cout << binpow(n, k) << "\n";
    }

    return 0;
}
