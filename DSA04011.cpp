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
        string s1, s2;
        cin >> s1 >> s2;
        ll num1 = 0, num2 = 0;
        int n1 = s1.size();
        int n2 = s2.size();
        for (int i = 0; i < s1.size(); i++)
            num1 += (s1[i] - '0') * pow(2, n1 - i - 1);
        for (int i = 0; i < n2; i++)
            num2 += (s2[i] - '0') * pow(2, n2 - i - 1);
        cout << num1 * num2 << "\n";
    }
    return 0;
}
