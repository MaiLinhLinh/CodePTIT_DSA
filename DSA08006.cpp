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
        queue<ll> qu;
        qu.push(9);
        while (!qu.empty()) {
            int x = qu.front();
            qu.pop();
            if (x % n == 0) {
                cout << x << "\n";
                break;
            } else {
                qu.push(x * 10 + 0);
                qu.push(x * 10 + 9);
            }
        }
    }

    return 0;
}
