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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int m, n;
        cin >> m >> n;
        int a[m + 1], b[n + 1], c[m + n + 1] = {};
        for (int i = 0; i < m; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++)
                c[i + j] += a[i] * b[j];
        }
        for (int i = 0; i < m + n - 1; i++)
            cout << c[i] << " ";
        cout << "\n";
    }

    return 0;
}
