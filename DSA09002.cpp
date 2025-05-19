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
    set<pair<int, int>> se;
    bool visited[55][55] = { 0 };
    cin.ignore();
    for (int i = 1; i <= n; i++) {
        string s;
        getline(cin, s);
        // cout << s << "\n";
        int num = 0;
        for (int j = 0; j < s.size(); j++) {
            if (isdigit(s[j])) {
                num = num * 10 + (s[j] - '0');
            } else {
                if (!visited[i][num]) {
                    se.insert({ i, num });
                    visited[i][num] = visited[num][i] = 1;
                }
                num = 0;
            }
        }
        if (num != 0 && !visited[i][num]) {
            se.insert({ i, num });
            visited[i][num] = visited[num][i] = 1;
        }
    }
    for (auto x : se) {
        cout << x.first << " " << x.second << "\n";
    }

    return 0;
}
