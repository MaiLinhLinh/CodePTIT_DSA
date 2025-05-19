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
        int a[n + 3];
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        a[0] = a[n + 1] = 0;
        stack<int> st;
        st.push(0);
        ll ans = 0;
        for (int i = 1; i <= n + 1; i++) {
            while (!st.empty() && a[i] < a[st.top()]) {
                int h = st.top();
                st.pop();
                int w = i - st.top() - 1;
                ans = max(ans, 1ll * a[h] * w);
            }
            st.push(i);
        }
        cout << ans << "\n";
    }

    return 0;
}
