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
int n;
int hang[15], chinh[30], phu[30];
int cnt = 0;

void Try(int j)
{
    for (int i = 1; i <= n; i++) {
        if (hang[i] == 0 && chinh[i - j + n] == 0 && phu[i + j - 1] == 0) {
            if (j == n)
                cnt++;
            else {
                hang[i] = chinh[i - j + n] = phu[i + j - 1] = 1;
                Try(j + 1);
                hang[i] = chinh[i - j + n] = phu[i + j - 1] = 0;
            }
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
    while (t--) {
        memset(hang, 0, sizeof(hang));
        memset(chinh, 0, sizeof(chinh));
        memset(phu, 0, sizeof(phu));
        cnt = 0;
        cin >> n;
        Try(1);
        cout << cnt << "\n";
    }

    return 0;
}
