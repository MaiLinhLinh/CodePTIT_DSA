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
string s;
ll ans = 0;

ll f[205] = { 0 };

void calc()
{
    f[0] = 1;
    for (int i = 1; i < n; i++) {
        if (s[i - 1] <= s[i])
            f[i] = f[i - 1] + 1;
        else
            f[i] = 1;
        ans = max(ans, f[i]);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    n = s.size();
    calc();
    cout << ans << "\n";
    return 0;
}
