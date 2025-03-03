#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;
int n, k;
int c[1005][1005];
void nCk()
{
    for (int i = 0; i <= 1001; i++) {
        c[i][0] = 1;
    }
    for (int i = 1; i <= 1001; i++) {
        c[i][1] = i;
    }
    for (int i = 2; i <= 1001; i++) {
        for (int j = 1; j <= i; j++) {
            c[i][j] = (c[i - 1][j - 1] % mod + c[i - 1][j] % mod) % mod;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    nCk();
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        cout << c[n][k] << "\n";
    }
}
