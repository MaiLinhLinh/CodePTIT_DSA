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
    ll x[3][3];
    friend matran operator*(matran a, matran b)
    {
        matran c;
        for (int i = 0; i, 3; i++) {
            for (int j = 0; j < 3; j++) {
                c.x[i][j] = 0;
                for (int k = 0; k < 3; k++) {
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
    }

    return 0;
}
