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
    int n;
    cin >> n;
    int a[n + 1];
    int maxx = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        maxx = max(maxx, a[i]);
    }
    // cout << maxx << '\n';
    int cnt = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == maxx) {
            cnt++;
            ans = max(ans, cnt);
        } else
            cnt = 0;
    }
    cout << ans << '\n';

    return 0;
}
