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
        if (s.size() % 2 != 0)
            cout << "-1\n";
        else {
            stack<char> st;
            for (int i = 0; i < s.size(); i++) {
                if (!st.empty() && s[i] == ')' && st.top() == '(')
                    st.pop();
                else
                    st.push(s[i]);
            }
            int k = st.size() / 2;
            int cnt = 0;
            while (!st.empty() && st.top() == '(') {
                st.pop();
                cnt++;
            }
            cout << k + (cnt % 2) << "\n";
        }
    }

    return 0;
}
