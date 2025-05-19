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
    ll x[2][2];
    friend matran operator*(matran a, matran b)
    {
        matran c;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                c.x[i][j] = 0;
                for (int k = 0; k < 2; k++) {
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
        cin >> n;
        matran a;
        a.x[0][0] = a.x[0][1] = a.x[1][0] = 1;
        a.x[1][1] = 0;
        matran res = binpow(a, n);
        cout << res.x[0][1] << "\n";
    }

    return 0;
}
