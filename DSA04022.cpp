#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;

/*
S1 = A, F1 = 1
S2 = ABA, F2 = 2F1 + 1
S3 = ABACABA, F3 = 2F2 + 1
S4 = ABACABA/D/ABACABA, F4 = 2F3 + 1;
nếu k <= F(n-1), thì vị trí của k trong Sn cx chính là vị trí của k trong S(n-1)
nếu k == F(n-1) + 1, thì vị trí của k trong Sn, là vị trí của kí tự (char)( n - 1 + 'A)
nếu k > F(n-1) + 1, thì vị trí của k trong Sn chính là vị trí của k - F(n-1) - 1 trong F(n-1).
*/

ll f[30];
void Calc()
{
    f[1] = 1;
    f[2] = 3;
    for (int i = 3; i <= 29; i++)
        f[i] = 2 * f[i - 1] + 1;
}

void Try(int n, ll k)
{
    if (n == 1)
        cout << "A";
    else {
        if (k <= f[n - 1])
            return Try(n - 1, k);
        else if (k == f[n - 1] + 1)
            cout << (char)(n - 1 + 'A');
        else
            return Try(n - 1, k - f[n - 1] - 1);
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
        cout << '\n';
    }

    return 0;
}
