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
int a[20];
string b[20];
void in()
{
    for (int i = 1; i <= k; i++) {
        cout << b[a[i]] << " ";
    }
    cout << "\n";
}

void Try(int i)
{
    for (int j = a[i - 1] + 1; j <= n - k + i; j++) {
        a[i] = j;
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
        string x;
        cin >> x;
        se.insert(x);
    }
    n = se.size();
    int d = 1;
    for (auto x : se) {
        b[d++] = x;
    }
    Try(1);

    return 0;
}
