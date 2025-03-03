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
int n, k, s, ok;
int a[25];
int b[25];
void sinh()
{
    int i = n;
    while (i >= 1 && a[i] == 1) {
        a[i] = 0;
        i--;
    }
    if (i == 0)
        ok = 0;
    else
        a[i] = 1;
}
bool check()
{
    int dem = 0, sum = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == 1) {
            dem++;
            sum += b[i];
        }
    }
    return (dem == k && sum == s);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while (cin >> n >> k >> s) {
        if (n == 0 && k == 0 && s == 0)
            break;
        else {
            ok = 1;
            for (int i = 1; i <= n; i++)
                a[i] = 0;
            for (int i = 1; i <= n; i++) {
                b[i] = i;
            }
            ll cnt = 0;
            while (ok) {
                if (check())
                    cnt++;
                sinh();
            }
            cout << cnt << '\n';
        }
    }

    return 0;
}
