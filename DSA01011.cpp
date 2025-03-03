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
int n, ok;
int a[100];
void sinh()
{
    int i = n - 1;
    while (i >= 1 && a[i] >= a[i + 1])
        i--;
    if (i == 0)
        ok = 0;
    else {
        int j = n;
        while (j > i && a[j] <= a[i])
            j--;
        // cout << i << " " << j << "\n";
        swap(a[i], a[j]);
        int l = i + 1, r = n;
        while (l <= r) {
            swap(a[l], a[r]);
            l++;
            r--;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int m;
        cin >> m;
        string s;
        cin >> s;
        n = s.size();
        for (int i = 1; i <= n; i++)
            a[i] = s[i - 1] - '0';
        ok = 1;
        sinh();
        cout << m << " ";
        if (ok == 0)
            cout << "BIGGEST\n";
        else {
            for (int i = 1; i <= n; i++)
                cout << a[i];
            cout << '\n';
        }
    }

    return 0;
}
