#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;
/*
G1 = A, F1 = 1;
G2 = B, F2 = 1;
G3 = AB, F3 = 2;
G4 = BAB, F4 = 3;
G5 = AB/BAB , F5 = 5;
nếu k <= F(n-2), thì vị trí của k trong Gn cx chính là vị trí của k trong G(n-2).
nếu k > F(n-2), thì vị trí của k trong Gn là vị trí của k - F(n-2) trong G(n-1).
*/

ll fibo[100];
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
        cout << "A";
    else if (n == 2)
        cout << "B";
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
    int t;
    cin >> t;
    Fibo();
    while (t--) {
        int n;
        ll i;
        cin >> n >> i;
        Try(n, i);
        cout << "\n";
    }

    return 0;
}
