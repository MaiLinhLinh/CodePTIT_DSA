#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;
int n;
int a[nmax];
int binarySeach(int k)
{
    int l = 0, r = n - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (a[mid] == k)
            return mid;
        else if (a[mid] < k)
            l++;
        else
            r--;
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> n >> k;

        for (int i = 0; i < n; i++)
            cin >> a[i];
        int ans = binarySeach(k);
        if (ans == -1)
            cout << "NO\n";
        else
            cout << ans + 1 << "\n";
    }
    return 0;
}
