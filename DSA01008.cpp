#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;
int n, k, ok;
int a[20];
void sinh()
{
    int i = n;
    while (i >= 1 && a[i] == 1) {
        a[i] = 0;
        i--;
    }
    if (i == 0)
        ok = 0;
    else
        a[i] = 1;
}
bool check()
{
    int dem = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == 1)
            dem++;
    }
    return dem == k;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
            a[i] = 0;
        ok = 1;
        while (ok) {
            if (check()) {
                for (int i = 1; i <= n; i++)
                    cout << a[i];
                cout << "\n";
            }
            sinh();
        }
    }

    return 0;
}
