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
void calc()
{
    vector<vector<int>> f(1005, vector<int>(1005, 0));
    for (int i = 0; i <= s.size() - 1; i++)
        f[i][i] = 1;
    int ans = 1;
    for (int i = 0; i < s.size() - 1; i++) {
        if (s[i] == s[i + 1])
            f[i][i + 1] = 1;
        ans = 2;
    }
    for (int len = 3; len <= s.size(); len++) {
        for (int i = 0; i <= s.size() - len; i++) {
            int j = i + len - 1;
            if (s[i] == s[j]) {
                f[i][j] = f[i + 1][j - 1];
                ans = max(ans, f[i][j]);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    return 0;
}
