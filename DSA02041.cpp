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

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({ 0, n });
        while (!pq.empty()) {
            pair<int, int> tmp = pq.top();
            pq.pop();
            if (tmp.second == 1) {
                cout << tmp.first << "\n";
                break;
            } else {
                if (tmp.second % 2 == 0)
                    pq.push({ tmp.first + 1, tmp.second / 2 });
                if (tmp.second % 3 == 0)
                    pq.push({ tmp.first + 1, tmp.second / 3 });
                pq.push({ tmp.first + 1, tmp.second - 1 });
            }
        }
    }

    return 0;
}
