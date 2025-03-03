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
int n, m;
int a[105][105];
ll c[105][105];
void Calc()
{
    c[0][0] = 0;
    for (int i = 1; i <= 101; i++) {
        c[0][i] = 1;
        c[i][0] = 1;
    }
    for (int i = 1; i <= 101; i++) {
        for (int j = 1; j <= 101; j++)
            c[i][j] = c[i - 1][j] + c[i][j - 1];
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
        cin >> m >> n;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++)
                cin >> a[i][j];
        }
        cout << c[m - 1][n - 1] << "\n";
    }
    return 0;
}
