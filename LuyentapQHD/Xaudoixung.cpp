#include <bits/stdc++.h>
using namespace std;
#ifdef MaiLinh
#include <debug.h>
#else
#define debug(...) 12
#endif
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(5e3 + 7)

bool f[nmax][nmax] = { 0 };

// f[i][j] la xau con tu i den j co doi xung khong
string s;

void calc()
{
    for (int i = 0; i <= s.size() - 1; i++) {
        f[i][i] = 1;
    }
    for (int i = 0; i < s.size() - 1; i++) {
        if (s[i] == s[i + 1])
            f[i][i + 1] = 1;
    }
    for (int len = 3; len <= s.size(); len++) {
        for (int i = 0; i <= s.size() - len; i++) {
            int j = i + len - 1;
            if (s[i] == s[j])
                f[i][j] = f[i + 1][j - 1];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    calc();
    int m;
    cin >> m;
    while (m--) {
        int l, r;
        cin >> l >> r;
        if (f[l - 1][r - 1] == 0)
            cout << "NO\n";
        else
            cout << "YES\n";
    }

    return 0;
}
