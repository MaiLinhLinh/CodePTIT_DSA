#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;
int x;
bool cmp(int a, int b)
{
    return abs(a - x) < abs(b - x);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n >> x;
        int a[n + 1];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        stable_sort(a, a + n, cmp);
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << "\n";
    }
    return 0;
}
