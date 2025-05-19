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
        queue<string> q;
        q.push("6");
        q.push("8");
        vector<ll> v;
        while (!q.empty()) {
            string x = q.front();
            q.pop();
            v.push_back(stoll(x));
            if ((x + "6").size() <= n)
                q.push(x + "6");
            if ((x + "8").size() <= n)
                q.push(x + "8");
        }
        sort(v.begin(), v.end(), greater<ll>());
        for (auto x : v)
            cout << x << " ";
        cout << "\n";
    }

    return 0;
}
