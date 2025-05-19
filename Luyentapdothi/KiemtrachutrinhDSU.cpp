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
int n, m, parent[100001], num[100001];
void init()
{
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        num[i] = i;
    }
}

int find(int u)
{
    if (u != parent[u])
        parent[u] = find(parent[u]);
    return parent[u];
}

bool Union(int u, int v)
{
    int a = find(u), b = find(v);
    if (a == b)
        return 0;
    if (num[a] < num[b])
        swap(a, b);
    parent[b] = a;
    num[a] += num[b];
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    return 0;
}
