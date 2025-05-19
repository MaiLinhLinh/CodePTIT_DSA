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

// vo huong, so dinh > 100000, dem so thanh phan lien thong
int n, m, parent[100001], num[100001];
void init()
{
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        num[i] = 1;
    }
}

int Find(int u)
{
    if (u != parent[u]) {
        parent[u] = Find(parent[u]);
    }
    return parent[u];
}

void Union(int u, int v)
{
    int a = Find(u), b = Find(v);
    if (a == b)
        return;
    if (num[a] < num[b])
        swap(a, b);
    parent[b] = a;
    num[a] += num[b];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, u, v, i;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        init();
        while (m--) {
            cin >> u >> v;
            Union(u, v);
        }

        int dem = 0;
        for (int i = 1; i <= n; i++) {
            if (parent[i] == i)
                dem++;
        }
        cout << dem << "\n";
    }
    return 0;
}
