#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;
int n, k, ok;
int b[25];
void sinh()
{
    int i = n;
    while (i >= 1 && b[i] == 1) {
        b[i] = 0;
        i--;
    }
    if (i == 0)
        ok = 0;
    else
        b[i] = 1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    int a[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        b[i] = 0;
    ok = 1;
    int dem = 0;
    while (ok) {
        ll sum = 0;
        for (int i = 1; i <= n; i++) {
            sum += (ll)a[i] * b[i];
        }
        if (sum == k) {
            dem++;
            for (int i = 1; i <= n; i++) {
                if (b[i] == 1)
                    cout << a[i] << " ";
            }
            cout << "\n";
        }
        sinh();
    }
    cout << dem << "\n";

    return 0;
}
