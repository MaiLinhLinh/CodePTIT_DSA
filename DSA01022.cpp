#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;
int n, ok;
int a[20];
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
        swap(a[i], a[j]);
        sort(a + i + 1, a + n + 1);
    }
}
bool check(int b[])
{
    for (int i = 1; i <= n; i++) {
        if (a[i] != b[i])
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
        cin >> n;
        int b[n + 2];
        for (int i = 1; i <= n; i++)
            cin >> b[i];
        for (int i = 1; i <= n; i++)
            a[i] = i;
        ok = 1;
        int cnt = 0;
        while (!check(b)) {
            // for (int i = 1; i <= n; i++)
            //     cout << a[i] << " ";
            // cout << "\n";
            cnt++;
            sinh();
        }
        cout << cnt + 1 << "\n";
    }
    return 0;
}
