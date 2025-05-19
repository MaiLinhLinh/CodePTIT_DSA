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
    int t;
    cin >> t;
    while (t--) {
        int d;
        cin >> d;
        string s;
        cin >> s;
        map<char, int> mp;
        for (int i = 0; i < s.size(); i++) {
            mp[s[i]]++;
        }
        int n = s.size();
        n = n + n % 2;
        bool ok = 0;
        for (auto x : mp) {
            if (x.second > (n / d)) {
                ok = 1;
                break;
            }
        }
        if (ok == 0)
            cout << "1\n";
        else
            cout << "-1\n";
    }

    return 0;
}
