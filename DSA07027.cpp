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
        ll a[n + 1];
        ll res[n + 1];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        stack<ll> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && a[i] >= st.top())
                st.pop();
            if (st.empty())
                res[i] = -1;
            else
                res[i] = st.top();
            st.push(a[i]);
        }
        for (int i = 0; i < n; i++)
            cout << res[i] << " ";
        cout << "\n";
    }

    return 0;
}
