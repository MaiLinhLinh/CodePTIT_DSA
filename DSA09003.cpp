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
        int v, e;
        cin >> v >> e;
        vector<vector<int>> adj(1005);
        while (e--) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
        }
        for (int i = 1; i <= v; i++) {
            cout << i << ": ";
            for (auto u : adj[i])
                cout << u << " ";
            cout << "\n";
        }
    }

    return 0;
}
