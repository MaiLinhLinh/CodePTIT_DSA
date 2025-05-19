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
int n, k, sum;
bool ans = 0;
int a[25];
void Try(int s, int tmp) // s la tong den hien tai, tmp la so luong tap con den hien tai
{
    if (ans)
        return;
    if (tmp == k) {
        ans = 1;
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (s == sum) // neu tong hien tai = sum thi tang so luong tap hop len 1
            Try(0, tmp + 1);
        else if (s < sum)
            Try(s + a[i], tmp);
        else
            return;
    }
}

void solve()
{
    cin >> n >> k;
    ans = 0;
    sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    if (sum % k != 0) {
        cout << "0\n";
        return;
    }
    sum /= k;
    Try(0, 0);
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
