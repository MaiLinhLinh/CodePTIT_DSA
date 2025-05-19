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

int Calc()
{
    stack<char> st;
    string s;
    getline(cin, s);
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= 'a' && s[i] <= 'z')
            continue;
        else if (s[i] != ')')
            st.push(s[i]);
        else {
            if (st.empty() || st.top() == '(')
                return 0;
            while (!st.empty() && st.top() != '(')
                st.pop();
            if (st.size() == 0)
                return 0;
            st.pop();
        }
    }
    return 1;
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
        int ans = Calc();
        if (ans == 1)
            cout << "No\n";
        else
            cout << "Yes\n";
    }

    return 0;
}
