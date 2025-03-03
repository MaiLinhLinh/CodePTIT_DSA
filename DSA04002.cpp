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
ll reveseNum(ll n)
{
    ll m = 0;
    while (n) {
        m = m * 10 + n % 10;
        n /= 10;
    }
    return m;
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
        ll r = reveseNum(n);
        cout << luythua(n, r) << "\n";
    }

    return 0;
}
