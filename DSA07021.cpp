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
        stack<int> st;
        st.push(-1);
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(')
                st.push(i); // push chi so
            else {
                st.pop(); // strong stack chi co 1 phan tu chi so sai gan nhat
                if (!st.empty())
                    ans = max(ans, i - st.top()); // ()())()() => st.top() = 4, i - st.top() se = 2, 4.
                else
                    st.push(i);
            }
        }
        cout << ans << "\n";
    }

    return 0;
}
