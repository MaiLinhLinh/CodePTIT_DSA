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
    stack<int> st;
    string s;
    while (cin >> s) {
        if (s == "push") {
            int x;
            cin >> x;
            st.push(x);
        } else if (s == "pop" && !st.empty()) {
            st.pop();
        } else if (s == "show" && !st.empty()) {
            stack<int> tmp = st;
            vector<int> v;
            while (!tmp.empty()) {
                v.push_back(tmp.top());
                tmp.pop();
            }
            for (int i = v.size() - 1; i >= 0; i--)
                cout << v[i] << " ";
            cout << "\n";
        } else if (st.empty()) {
            cout << "empty\n";
        }
    }

    return 0;
}
