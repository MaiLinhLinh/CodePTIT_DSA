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
int n, ok;
int a[20];
void sinh()
{
    int i = n;
    while (i >= 1 && a[i] == 1) {
        a[i] = 0;
        i--;
    }
    if (i == 0)
        ok = 0;
    else
        a[i] = 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        string s;
        cin >> s;
        for (int i = 1; i <= n; i++)
            a[i] = 0;
        ok = 1;
        vector<vector<char>> ans;
        while (ok) {
            vector<char> tmp;
            for (int i = 1; i <= n; i++) {
                if (a[i] == 1) {
                    tmp.push_back(s[i - 1]);
                }
            }
            ans.push_back(tmp);
            sinh();
        }
        sort(ans.begin(), ans.end());
        for (int i = 0; i < ans.size(); i++) {
            for (int j = 0; j < ans[i].size(); j++)
                cout << ans[i][j];
            cout << " ";
        }
        cout << "\n";
    }

    return 0;
}
