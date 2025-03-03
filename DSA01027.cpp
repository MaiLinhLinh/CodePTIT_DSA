#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;
int n, ok;
int a[10];
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
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    ok = 1;
    while (ok) {
        for (int i = 1; i <= n; i++)
            cout << a[i] << " ";
        cout << "\n";
        sinh();
    }
    return 0;
}
