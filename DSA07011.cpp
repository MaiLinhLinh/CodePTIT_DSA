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
    if (x == '*' || x == '/')
        return 2;
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
        stack<string> st1;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
                string a = st1.top();
                st1.pop();
                string b = st1.top();
                st1.pop();
                string tmp = '(' + b + s[i] + a + ')';
                st1.push(tmp);

            } else {
                st1.push(string(1, s[i]));
            }
        }
        string t = st1.top();
        // cout << t << "\n";
        stack<char> st2;
        string ans = "";
        for (int i = t.size() - 1; i >= 0; i--) {
            if (isalpha(t[i])) {
                ans = t[i] + ans;
            } else if (t[i] == ')')
                st2.push(t[i]);
            else if (t[i] == '(') {
                while (!st2.empty() && st2.top() != ')') {
                    ans = st2.top() + ans;
                    st2.pop();
                }
                st2.pop();
            } else {
                while (!st2.empty() && precedence(st2.top()) >= precedence(t[i])) {
                    ans = st2.top() + ans;
                    st2.pop();
                }
                st2.push(t[i]);
            }
        }
        while (!st2.empty()) {
            if (st2.top() != '(')
                ans = st2.top() + ans;
            st2.pop();
        }
        cout << ans << "\n";
    }

    return 0;
}
