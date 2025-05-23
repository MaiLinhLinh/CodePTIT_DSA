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
int n, ok;
int a[15];

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
            int gray[n + 1];
            gray[1] = a[1];
            for (int i = 2; i <= n; i++) {
                int c = a[i] ^ a[i - 1];
                gray[i] = c;
            }
            for (int i = 1; i <= n; i++)
                cout << gray[i];
            cout << " ";
            sinh();
        }
        cout << "\n";
    }

    return 0;
}
