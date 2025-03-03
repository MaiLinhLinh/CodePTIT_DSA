#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;
int n, ok;
int a[10005];
void sinh()
{
    int i = n - 1;
    while (i >= 1 && a[i] > a[i + 1])
        i--;
    if (i == 0)
        ok = 0;
    else {
        int j = n;
        while (j > i && a[j] < a[i])
            j--;
        // cout << "i: " << i << ", j: " << j << "\n";
        swap(a[i], a[j]);
        int l = i + 1, r = n;
        while (l <= r) {
            int tmp = a[l];
            a[l] = a[r];
            a[r] = tmp;
            l++;
            r--;
        }
        // sort(a + i + 1, a + n + 1);
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
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        ok = 1;
        sinh();
        if (ok == 0) {
            for (int i = 1; i <= n; i++)
                a[i] = i;
        }
        for (int i = 1; i <= n; i++)
            cout << a[i] << " ";
        cout << "\n";
    }
    return 0;
}
