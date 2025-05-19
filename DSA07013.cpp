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

int tinh(int a, int b, char c)
{
    if (c == '+')
        return a + b;
    if (c == '-')
        return a - b;
    if (c == '*')
        return a * b;
    if (c == '/')
        return a / b;
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
        stack<int> st;
        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                st.push(s[i] - '0');
            } else {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(tinh(b, a, s[i]));
            }
        }
        cout << st.top() << "\n";
    }

    return 0;
}
