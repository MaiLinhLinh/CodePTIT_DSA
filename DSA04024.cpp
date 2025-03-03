#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;
int n, m;

struct matran {
    ll x[15][15];
    friend matran operator*(matran a, matran b)
    {
        matran c;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                c.x[i][j] = 0;
                for (int k = 1; k <= n; k++) {
                    c.x[i][j] += (a.x[i][k] % mod * b.x[k][j] % mod) % mod;
                    c.x[i][j] %= mod;
                }
            }
        }
        return c;
    }
};
matran binpow(matran a, ll n)
{
    if (n == 1)
        return a;
    matran tmp = binpow(a, n / 2);
    if (n % 2)
        return tmp * tmp * a;
    else
        return tmp * tmp;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        matran a;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> a.x[i][j];
            }
        }
        matran res = binpow(a, m);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << res.x[i][j] << " ";
            }
            cout << '\n';
        }

        ll ans = 0;
        for (int i = 1; i <= n; i++) {
            ans += res.x[i][n];
            ans %= mod;
        }
        cout << ans << "\n";
    }

    return 0;
}
