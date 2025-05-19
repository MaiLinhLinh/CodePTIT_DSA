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

// đối với bài toán duyệt từ đỉnh u đến đỉnh v, cần lưu lại đỉnh cha
int parent[nmax];
bool visited[nmax];
vector<vector<int>> adj(1005);

void bfs(int u, int dich)
{
    queue<int> q;
    q.push(u);
    parent[u] = -1;
    visited[u] = true;
    while (!q.empty()) {
        u = q.front();
        if (u == dich)
            break;
        q.pop();
        for (auto v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                parent[v] = u;
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
        memset(parent, 0, sizeof(parent));
        memset(visited, 0, sizeof(visited));
        for (int i = 0; i < adj.size(); i++) {
            adj[i].clear();
        }

        int v, e, u, dich;
        cin >> v >> e >> u >> dich;
        for (int i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
        }
        bfs(u, dich);
        if (!visited[dich])
            cout << "-1\n";
        else {
            vector<int> ans;
            while (dich != -1) {
                ans.push_back(dich);
                dich = parent[dich];
            }

            for (int i = ans.size() - 1; i >= 0; i--)
                cout << ans[i] << " ";
            cout << "\n";
        }
    }
    return 0;
}
