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
int n, s;
int a[35];
int b[35];

int res = 1e9;
void Try(int i, int start, int currentSum)
{
    if (i >= res)
        return;
    for (int j = start; j <= n; j++) {
        b[i] = a[j];
        currentSum += b[i];
        if (currentSum == s) {
            res = min(res, i);
        } else if (currentSum < s)
            Try(i + 1, j + 1, currentSum);
        currentSum -= b[i];
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> s;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    Try(1, 1, 0);
    cout << res << '\n';
    return 0;
}
