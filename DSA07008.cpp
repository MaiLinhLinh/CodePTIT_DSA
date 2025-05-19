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

int precedence(char x)
{
    if (x == '+' || x == '-')
        return 1;
    if (x == '/' || x == '*')
        return 2;
    if (x == '^')
        return 3;
    return 0;
}

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
        stack<char> st; // chi push cac dau
        string ans = "";
        for (auto x : s) {
            if (isalpha(x))
                ans += x;
            else if (x == '(')
                st.push(x);
            else if (x == ')') {
                while (!st.empty() && st.top() != '(') {
                    ans += st.top();
                    st.pop();
                }
                st.pop();
            } else {
                while (!st.empty() && precedence(st.top()) >= precedence(x)) {
                    ans += st.top();
                    st.pop();
                }
                st.push(x);
            }
        }
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        cout << ans << "\n";
    }

    return 0;
}
