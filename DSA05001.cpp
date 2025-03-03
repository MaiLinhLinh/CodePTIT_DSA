#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        map<char, int> mp;
        for (int i = 0; i < s1.size(); i++)
            mp[s1[i]] = 1;
        for (int i = 0; i < s2.size(); i++) {
            if (mp[s2[i]] == 1)
                mp[s2[i]] = 2;
        }
        int ans = 0;
        for (auto x : mp) {
            if (x.second == 2)
                ans++;
        }
        cout << ans << "\n";
    }

    return 0;
}
