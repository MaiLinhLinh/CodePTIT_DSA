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

bool visited[nmax];
vector<vector<int>> adj(1005);

void bfs(int u)
{
    queue<int> q;
    visited[u] = true;
    q.push(u);
    while (!q.empty()) {
        u = q.front();
        q.pop();
        for (auto v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
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
        memset(visited, 0, sizeof(visited));
        for (int i = 0; i < adj.size(); i++) {
            adj[i].clear();
        }
        int n, m;
        cin >> n >> m;
        while (m--) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        int maxx = 0;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            memset(visited, 0, sizeof(visited));
            visited[i] = 1;
            int cnt = 0;
            for (int j = 1; j <= n; j++) {
                if (!visited[j]) {
                    cnt++;
                    bfs(j);
                }
            }
            if (cnt > maxx) {
                maxx = cnt;
                ans = i;
            }
        }
        if (maxx == 1)
            cout << "0\n";
        else {
            cout << ans << "\n";
        }
    }

    return 0;
}
