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
        getline(cin, s);
        stack<string> st;
        stringstream ss(s);
        string word;
        while (ss >> word) {
            st.push(word);
        }
        while (!st.empty()) {
            cout << st.top() << " ";
            st.pop();
        }
        cout << "\n";
    }

    return 0;
}
