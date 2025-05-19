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

int n;
struct matran {
    ll x[15][15];
    friend matran operator*(matran a, matran b)
    {
        matran c;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                c.x[i][j] = 0;
                for (int k = 0; k < n; k++) {
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
        int k;
        cin >> n >> k;
        matran a;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> a.x[i][j];
            }
        }
        matran res = binpow(a, k);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cout << res.x[i][j] << " ";
            cout << "\n";
        }
    }

    return 0;
}
