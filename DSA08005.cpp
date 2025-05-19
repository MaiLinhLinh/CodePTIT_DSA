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
        int n;
        cin >> n;
        queue<string> qu;
        qu.push("1");
        while (n--) {
            string s = qu.front();
            cout << s << " ";
            qu.pop();
            qu.push(s + "0");
            qu.push(s + "1");
        }
        cout << "\n";
    }

    return 0;
}
