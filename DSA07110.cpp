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
    cin.ignore();
    while (t--) {
        string s;
        cin >> s;
        stack<char> st;
        for (auto x : s) {
            if (x == '{' || x == '[' || x == '(')
                st.push(x);
            else if (x == ']' && !st.empty() && st.top() == '[')
                st.pop();
            else if (x == ')' && !st.empty() && st.top() == '(')
                st.pop();
            else if (x == '}' && !st.empty() && st.top() == '{')
                st.pop();
        }
        if (st.empty())
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
