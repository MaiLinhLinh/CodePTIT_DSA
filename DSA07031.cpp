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

ll tinh(ll a, ll b, string c)
{
    if (c == "+")
        return a + b;
    if (c == "-")
        return a - b;
    if (c == "*")
        return a * b;
    if (c == "/")
        return a / b;
}

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
        string s[n + 1];
        for (int i = 0; i < n; i++)
            cin >> s[i];
        stack<ll> st;
        for (int i = n - 1; i >= 0; i--) {
            if (isdigit(s[i].back())) {
                st.push(stoll(s[i]));
            } else {
                ll a = st.top();
                st.pop();
                ll b = st.top();
                st.pop();
                st.push(tinh(a, b, s[i]));
            }
        }
        cout << st.top() << "\n";
    }
    return 0;
}
