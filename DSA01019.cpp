#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;
int n, ok;
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
    if (a[1] == 0 || a[n] == 1)
        return 0;
    for (int i = 2; i <= n; i++) {
        if (a[i] == 1 && a[i - 1] == 1)
            return 0;
    }
    return 1;
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
        for (int i = 1; i <= n; i++)
            a[i] = 0;
        ok = 1;
        while (ok) {
            if (check()) {
                for (int i = 1; i <= n; i++) {
                    if (a[i] == 1)
                        cout << "H";
                    else
                        cout << "A";
                }
                cout << "\n";
            }
            sinh();
        }
    }

    return 0;
}
