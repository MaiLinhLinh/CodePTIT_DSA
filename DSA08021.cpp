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
        int m, n;
        cin >> m >> n;
        int a[m + 1][n + 1];
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++)
                cin >> a[i][j];
        }
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        // first la so buoc di
        pq.push({ 0, { 1, 1 } });
        bool check = 0;
        bool visited[m + 1][n + 1] = { 0 };
        visited[1][1] = 1;
        while (!pq.empty()) {
            auto [step, xy] = pq.top();
            pq.pop();
            auto [x, y] = xy;
            if (x == m && y == n) {
                cout << step << "\n";
                check = 1;
                break;
            }
            if (y + a[x][y] <= n && !visited[x][y + a[x][y]]) {
                pq.push({ step + 1, { x, y + a[x][y] } });
                visited[x][y + a[x][y]] = 1;
            }
            if (x + a[x][y] <= m && !visited[x + a[x][y]][y]) {
                pq.push({ step + 1, { x + a[x][y], y } });
                visited[x + a[x][y]][y] = 1;
            }
        }
        if (check == 0)
            cout << "-1\n";
    }

    return 0;
}
