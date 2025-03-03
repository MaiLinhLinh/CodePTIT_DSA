#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;
int n, k;
int a[30];
void sinh()
{
    int i = k;
    while (i >= 1 && a[i] == (n - k + i))
        i--;
    if (i != 0) {
        a[i]++;
        for (int j = i + 1; j <= k; j++)
            a[j] = a[j - 1] + 1;
    }
}
bool check(int b[])
{
    for (int i = 1; i <= k; i++) {
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
        cin >> n >> k;
        int b[k + 2];
        for (int i = 1; i <= k; i++)
            cin >> b[i];
        for (int i = 1; i <= k; i++)
            a[i] = i;
        int cnt = 0;
        while (!check(b)) {
            cnt++;
            sinh();
        }
        cout << cnt + 1 << "\n";
    }

    return 0;
}
