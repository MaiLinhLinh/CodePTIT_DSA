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
ll f[55];
void Calc()
{
    f[1] = 1;
    f[2] = 3;
    for (int i = 3; i <= 50; i++)
        f[i] = f[i - 1] * 2 + 1;
}

void Try(int n, ll k)
{
    if (n == 1)
        cout << "1\n";
    else {
        if (k == f[n - 1] + 1)
            cout << n << "\n";
        else if (k <= f[n - 1])
            Try(n - 1, k);
        else
            Try(n - 1, k - f[n - 1] - 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Calc();
    int t;
    cin >> t;
    while (t--) {
        int n;
        ll k;
        cin >> n >> k;
        Try(n, k);
    }

    return 0;
}
