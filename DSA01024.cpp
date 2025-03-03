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
int n, k;
vector<int> b(35);
string a[35];

void in()
{
    // debug(b);
    for (int i = 1; i <= k; i++)
        cout << a[b[i]] << " ";
    cout << '\n';
}

void Try(int i)
{
    for (int j = b[i - 1] + 1; j <= n - k + i; j++) {
        b[i] = j;
        if (i == k)
            in();
        else
            Try(i + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    set<string> se;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        se.insert(a[i]);
    }
    fill(a, a + n, "");
    int d = 1;
    for (auto x : se) {
        a[d++] = x;
    }
    n = d - 1;
    Try(1);

    return 0;
}
