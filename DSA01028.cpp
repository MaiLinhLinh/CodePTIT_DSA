#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;
int n, k, ok;
int a[25];
void sinh()
{
    int i = k;
    while (i >= 1 && a[i] == (n - k + i))
        i--;
    if (i == 0)
        ok = 0;
    else {
        a[i]++;
        for (int j = i + 1; j <= k; j++)
            a[j] = a[j - 1] + 1;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int m;
    set<int> se;
    cin >> m >> k;
    for (int i = 1; i <= m; i++) {
        int x;
        cin >> x;
        se.insert(x);
    }
    n = se.size();
    int d = 1;
    int b[25];
    for (auto x : se) {
        b[d++] = x;
    }
    for (int i = 1; i <= k; i++)
        a[i] = i;
    ok = 1;
    while (ok) {
        for (int i = 1; i <= k; i++)
            cout << b[a[i]] << " ";
        cout << "\n";
        sinh();
    }

    return 0;
}
