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
int n;
int a[25];
string b[25];
vector<vector<string>> v;
void check()
{
    vector<string> tmp;
    for (int i = 1; i <= n; i++) {
        if (a[i] == 1)
            tmp.push_back(b[i]);
    }
    debug(tmp);
    if (tmp.size() < 2)
        return;
    for (int i = 1; i < tmp.size(); i++) {
        if (stoi(tmp[i]) <= stoi(tmp[i - 1]))
            return;
    }
    v.push_back(tmp);
    return;
}

void Try(int i)
{
    for (int j = 0; j <= 1; j++) {
        a[i] = j;
        if (i == n) {
            check();
        } else if (i < n)
            Try(i + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    Try(1);
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
