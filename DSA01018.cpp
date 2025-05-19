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
bool checkdau(int a[])
{
    for (int i = 1; i <= k; i++) {
        if (a[i] != i)
            return 0;
    }
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        int a[k + 1];
        for (int i = 1; i <= k; i++)
            cin >> a[i];
        if (checkdau(a)) {
            for (int i = k; i <= n; i++)
                cout << i << " ";
            cout << "\n";
        } else {
            int i = k;
            while (i >= 2 && a[i] - a[i - 1] == 1)
                i--;
            a[i]--;
            if (i < k)
                a[k] = n;

            for (int j = k - 1; j >= i + 1; i--)
                a[j] = a[j + 1] - 1;

            for (int i = 1; i <= k; i++)
                cout << a[i] << " ";
            cout << "\n";
        }
    }

    return 0;
}
