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
        string s;
        cin >> s;
        map<char, int> mp;
        for (auto x : s) {
            mp[x]++;
        }
        int n = s.size();
        n = n + n % 2;
        bool ok = 0;
        for (auto x : mp) {
            if (x.second > (n / 2)) {
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
