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

int n, m, k;

void check(int a[], int b[], int c[])
{
    vector<int> v;
    int l1 = 0, l2 = 0, l3 = 0;
    while (l1 < n && l2 < m && l3 < k) {
        if (a[l1] == b[l2] && b[l2] == c[l3]) {
            v.push_back(a[l1]);
            l1++;
            l2++;
            l3++;
        } else if (a[l1] < b[l2]) {
            l1++;
        } else if (b[l2] < c[l3])
            l2++;
        else
            l3++;
    }

    if (v.size() == 0)
        cout << "NO";
    else {
        for (auto x : v)
            cout << x << " ";
    }
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m >> k;
        int a[n + 1], b[m + 1], c[k + 1];

        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];
        for (int i = 0; i < k; i++)
            cin >> c[i];

        check(a, b, c);
    }
    return 0;
}
