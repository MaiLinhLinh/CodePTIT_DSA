#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;
int n, ok;
int a[25];
void sinh(int m)
{
    int i = m;
    while (i >= 1 && a[i] == 1) {
        a[i] = 0;
        i--;
    }
    if (i == 0)
        ok = 0;
    else
        a[i] = 1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int m = (n + 1) / 2;
    for (int i = 1; i <= m; i++)
        a[i] = 0;
    ok = 1;
    while (ok) {
        if (n % 2 == 0) {
            for (int i = 1; i <= m; i++)
                cout << a[i] << " ";
            for (int i = m; i >= 1; i--)
                cout << a[i] << " ";
            cout << "\n";

        } else {
            for (int i = 1; i <= m; i++)
                cout << a[i] << " ";
            for (int i = m - 1; i >= 1; i--)
                cout << a[i] << " ";
            cout << "\n";
        }
        sinh(m);
    }

    return 0;
}
