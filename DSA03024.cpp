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

bool cmp(pair<int, int> p, pair<int, int> q)
{
    return p.second < q.second;
}
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
        pair<int, int> pii[n];
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            pii[i] = { x, y };
        }
        sort(pii, pii + n, cmp);
        int cnt = 0;
        int fi = 0;
        for (int i = 0; i < n; i++) {
            if (pii[i].first >= fi) {
                cnt++;
                fi = pii[i].second;
            }
        }
        cout << cnt << "\n";
    }

    return 0;
}
