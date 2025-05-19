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
int n, k;
int ans = 0;
int a[200], b[200];
void Try(int pos1, int pos2)
{
    if (pos2 == k) {
        ans++;
        return;
    }
    for (int i = pos1 + 1; i < n; i++) {
        if (a[i] > a[pos1]) {
            b[pos2 + 1] = a[i];
            Try(i, pos2 + 1);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++) {
        b[1] = a[i];
        Try(i, 1);
    }
    cout << ans << "\n";

    return 0;
}
