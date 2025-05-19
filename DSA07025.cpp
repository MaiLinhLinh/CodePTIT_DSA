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

ll tinhgiatri(ll a, ll b, char(c))
{
    if (c == '+')
        return a + b;
    else if (c == '-')
        return a - b;
    else if (c == '*')
        return a * b;
    else if (c == '/')
        return a / b;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cin.ignore();
        string s;
        getline(cin, s);
        stack<ll> st;
        int num = 0;
        bool check = 0;
        for (int i = 0; i < s.size(); i++) {
            if (i != s.size() - 1 && s[i] == '-' && isdigit(s[i + 1]))
                check = 1;
            else if (isdigit(s[i]))
                num = num * 10 + (s[i] - '0');
            else if (s[i] == ' ' && isdigit(s[i - 1])) {
                if (check == 1) {
                    num = 0 - num;
                    check = 0;
                }
                st.push(num);
                num = 0;
            } else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
                ll a = st.top();
                st.pop();
                ll b = st.top();
                st.pop();
                ll x = tinhgiatri(b, a, s[i]);
                st.push(x);
            }
        }
        cout << st.top() << "\n";
    }

    return 0;
}
