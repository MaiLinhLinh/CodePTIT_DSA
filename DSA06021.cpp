#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;

int binarySearch(int l, int r, int a[], int x)
{
    while (l <= r) {
        int mid = (l + r) / 2;
        if (a[mid] == x)
            return mid;
        else if (a[mid] < x)
            l = mid + 1;
        else
            r = mid - 1;
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
        int n, x;
        cin >> n >> x;
        int a[n + 1];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int tmp = a[0];
        int pos;
        for (int i = 1; i < n; i++) {
            if (a[i] > tmp)
                tmp = a[i];
            else {
                pos = i;
                break;
            }
        }
        int ans = binarySearch(0, pos - 1, a, x);
        if (ans == -1) {
            ans = binarySearch(pos, n - 1, a, x);
        }
        cout << ans + 1 << "\n";
    }

    return 0;
}
