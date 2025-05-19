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
        vector<pair<int, int>> pii(n);
        for (int i = 0; i < n; i++) {
            cin >> pii[i].first >> pii[i].second;
        }
        sort(pii.begin(), pii.end(), cmp);
        int finish = 0, cnt = 0;
        for (int i = 0; i < n; i++) {
            if (pii[i].first >= finish) {
                cnt++;
                finish = pii[i].second;
            }
        }
        cout << cnt << "\n";
    }

    return 0;
}
