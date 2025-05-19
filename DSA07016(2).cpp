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
        stack<string> st;
        st.push("1");
        int cnt = 2;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'D') {
                // vi du stack co 7, ma gap ki tu D, thi tuc la no se phai giam tu 8 xuong 7 => lay 7 ra , push 8, push7
                string a = st.top();
                st.pop();
                st.push(to_string(cnt) + a);
            } else if (s[i] == 'I') {
                st.push(to_string(cnt));
            }
            cnt++;
        }
        vector<string> v;
        while (!st.empty()) {
            v.push_back(st.top());
            st.pop();
        }
        for (int i = v.size() - 1; i >= 0; i--)
            cout << v[i];

        cout << "\n";
    }

    return 0;
}
