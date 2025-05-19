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

int n, m, start, D[1005];
vector<pair<int, int>> List[1005];

void Dijkstra(int start)
{
    int i, u, v;
    for (i = 1; i < n; i++)
        D[i] = 1e9;
    D[start] = 0;
    while (!Q.empty())
        Q.pop();
    Q.push({ 0, start });
    while (!Q.empty()) {
        u = Q.top().second;
        Q.pop();
        for (i = 0; i < List[u].size(); i++) {
            v = List[u][i].second;
            int d_u_v = List[u][i].first;
            if (D[u] + d_u_v < D[v]) {
                D[v] = D[u] + d_u_v;
                Q.push({ D[v], v });
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    return 0;
}
