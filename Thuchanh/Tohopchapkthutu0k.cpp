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
int n, k, ok;
int a[35];
int d = 0;
void sinh()
{
    int i = k;
    while (i >= 1 && a[i] == n - k + i)
        i--;
    if (i == 0)
        ok = 0;
    else {
        a[i]++;
        int j = i + 1;
        while (j <= k) {
            a[j] = a[j - 1] + 1;
            j++;
        }
    }
    d++;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= k; i++)
        a[i] = i;
    ok = 1;
    while (ok) {
        if (d % k == 0) {
            for (int i = 1; i <= k; i++)
                cout << a[i] << " ";
            cout << "\n";
        }
        sinh();
    }

    return 0;
}
