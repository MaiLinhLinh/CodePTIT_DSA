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
int n, ok;
int a[10];
void sinh()
{
    // bat dau tu cuoi, tim a[i] < a[i+1];
    int i = n - 1;
    while (i >= 1 && a[i] >= a[i + 1])
        --i;
    if (i == 0)
        ok = 0;
    else {
        int j = n;
        while (j >= i && a[j] <= a[i])
            j--;
        swap(a[i], a[j]);
        int l = i + 1, r = n;
        while (l <= r) {
            swap(a[l], a[r]);
            l++;
            r--;
        }
        // reverse( a + i + 1, a+ n + 1);
    }
}
bool check()
{
    int kc = 0;
    for (int i = 1; i < n; i++) {
        kc += (a[i] - a[i + 1]);
    }
    return kc > 0;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        a[i] = i;
    ok = 1;
    while (ok) {
        if (check()) {
            for (int i = 1; i <= n; i++)
                cout << a[i] << " ";
            cout << "\n";
        }
        sinh();
    }

    return 0;
}
