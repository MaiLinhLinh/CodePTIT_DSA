#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n + 1];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n);
        int l = 0, r = n - 1;
        while (l <= r) {
            if (l == r)
                cout << a[l] << " ";
            else
                cout << a[r] << " " << a[l] << " ";
            l++;
            r--;
        }
        cout << "\n";
    }

    return 0;
}
