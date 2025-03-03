#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;

ll fibo[93];
void Fibo()
{
    fibo[1] = 1;
    fibo[2] = 1;
    for (int i = 3; i <= 92; i++)
        fibo[i] = fibo[i - 2] + fibo[i - 1];
}
void Try(int n, ll k)
{
    if (n == 1)
        cout << "0";
    else if (n == 2)
        cout << "1";
    else {
        if (k <= fibo[n - 2])
            return Try(n - 2, k);
        else
            return Try(n - 1, k - fibo[n - 2]);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Fibo();
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
