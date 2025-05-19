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
        int a[n + 1];
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        stack<ll> st;
        ll res[n + 1];
        for (int i = 1; i <= n; i++) {
            while (!st.empty() && a[i] >= a[st.top()])
                st.pop();
            if (st.empty())
                res[i] = i;
            else
                res[i] = i - st.top();
            st.push(i);
        }
        for (int i = 1; i <= n; i++)
            cout << res[i] << " ";
        cout << "\n";
    }
    return 0;
}
