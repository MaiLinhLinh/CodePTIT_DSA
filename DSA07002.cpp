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
    int q;
    cin >> q;
    stack<int> st;
    while (q--) {
        string s;
        cin >> s;
        if (s == "PUSH") {
            int x;
            cin >> x;
            st.push(x);
        } else if (s == "POP" && !st.empty()) {
            st.pop();
        } else if (s == "PRINT") {
            if (!st.empty())
                cout << st.top() << "\n";
            else
                cout << "NONE" << endl;
        }
    }

    return 0;
}
