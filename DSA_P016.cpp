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
int hang[10], chinh[20], phu[20];
ll ans = 0;
int a[10][10];

void Try(int j, ll sum)
{
    for (int i = 1; i <= 8; i++) {
        if (hang[i] == 0 && chinh[i - j + 8] == 0 && phu[i + j - 1] == 0) {
            hang[i] = chinh[i - j + 8] = phu[i + j - 1] = 1;
            sum += a[i][j];
            if (j == 8) {
                ans = max(sum, ans);
            } else
                Try(j + 1, sum);
            hang[i] = chinh[i - j + 8] = phu[i + j - 1] = 0;
            sum -= a[i][j];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int x = 1; x <= t; x++) {
        memset(hang, 0, sizeof(hang));
        memset(chinh, 0, sizeof(chinh));
        memset(phu, 0, sizeof(phu));
        ans = 0;

        for (int i = 1; i <= 8; i++) {
            for (int j = 1; j <= 8; j++) {
                cin >> a[i][j];
            }
        }
        Try(1, 0);
        cout << "Test " << x << ": ";
        cout << ans << '\n';
    }

    return 0;
}
