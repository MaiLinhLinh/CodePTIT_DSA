#include <bits/stdc++.h>
using namespace std;
#ifdef HoangHoangTuan
#include <debug.h>
#else
#define debug(...) 12
#endif
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)

string ans, s;
void Try(int k, int curIdx)
{
    // dieu kien dung
    if (k == 0 || curIdx == s.size())
        return;
    char MAX = s[curIdx];
    for (int i = curIdx + 1; i < s.size(); i++) {
        MAX = max(MAX, s[i]);
    }
    for (int i = s.size() - 1; i > curIdx; i--) {
        if (s[i] == MAX) {
            if (MAX != s[curIdx]) {
                swap(s[i], s[curIdx]);
                ans = max(ans, s);
                Try(k - 1, curIdx + 1);
                swap(s[i], s[curIdx]);
            } else
                Try(k, curIdx + 1);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k >> s;
        ans = "";
        debug(s);
        Try(k, 0);
        cout << ans << "\n";
    }

    return 0;
}