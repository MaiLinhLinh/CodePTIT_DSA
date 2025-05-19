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
        string s;
        cin >> s;
        stack<char> st;
        int ok = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                st.push(s[i]);
            else {
                if (!st.empty()) {
                    char x = st.top();
                    if (x == '(' && s[i] == ')')
                        st.pop();
                    else if (x == '[' && s[i] == ']')
                        st.pop();
                    else if (x == '{' && s[i] == '}')
                        st.pop();
                } else {
                    cout << "false\n";
                    ok = 1;
                    break;
                }
            }
        }
        if (ok == 0) {
            if (st.empty())
                cout << "true\n";
            else
                cout << "false\n";
        }
    }

    return 0;
}
