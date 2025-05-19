#include <bits/stdc++.h>
using namespace std;
#define faster()                  \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
long long parent[100005];
long long num[100005];
void init()
{
    for (int i = 1; i <= 100005; i++) {
        parent[i] = i;
        num[i] = 1;
    }
}

int find(int x)
{
    while (x != parent[x]) {
        x = parent[x];
    }
    return parent[x];
}

void Union(int u, int v)
{
    int a = find(u), b = find(v);
    if (a == b)
        return;
    if (num[a] < num[b])
        swap(a, b);
    parent[b] = a;
    num[a] += num[b];
}

int main()
{
    faster()
        init();
    long long n, m;
    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        Union(u, v);
    }
    int k = find(1);
    int res = 0;
    for (int i = 1; i <= n; i++) {
        int se = find(i);
        if (se != k && num[se] > res)
            res = num[se];
    }
    cout << num[k] + res << "\n";
}
