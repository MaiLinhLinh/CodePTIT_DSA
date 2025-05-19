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
        string s;
        cin >> s;
        int cntD[10] = { 0 };
        int cnt = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == 'D') {
                cnt++;
            } else {
                cntD[i] = cnt;
                cnt = 0;
            }
        }
        // trong truong hop D o dau thi cnt != 0;
        cout << 1 + cnt;
        int maxx = 1 + cnt;
        int maxtmp = maxx;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'D') {
                cout << maxtmp - 1;
                maxtmp -= 1;
            } else {
                cout << maxx + cntD[i] + 1;
                maxx += cntD[i] + 1;
                maxtmp = maxx;
            }
        }
        cout << "\n";
    }

    return 0;
}
