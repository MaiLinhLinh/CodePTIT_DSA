#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;
ll MaxNum(string a, string b)
{
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == '5')
            a[i] = '6';
        if (b[i] == '5')
            b[i] = '6';
    }
    return stol(a) + stol(b);
}

ll MinNum(string a, string b)
{
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == '6')
            a[i] = '5';
        if (b[i] == '6')
            b[i] = '5';
    }
    return stol(a) + stol(b);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string a, b;
    cin >> a >> b;
    ll minn = MinNum(a, b);
    ll maxx = MaxNum(a, b);
    cout << minn << " " << maxx << '\n';

    return 0;
}
