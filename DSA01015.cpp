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
    int i = 5;
    while (i >= 1 && a[i] == 1) {
        a[i] = 0;
        i--;
    }
    if (i == 0)
        ok = 0;
    else
        a[i] = 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int m;
        cin >> m;
        for (int i = 1; i <= 5; i++)
            a[i] = 0;
        ok = 1;
        while (ok) {
            int sum = 0;
            int check = 0;
            for (int i = 1; i <= 5; i++) {
                if (a[i] == 1)
                    sum = sum * 10 + 9;
                else
                    sum = sum * 10;
                if (sum > 0 && sum % m == 0) {
                    check = 1;
                    cout << sum << "\n";
                    break;
                }
            }
            if (check == 1)
                break;
            sinh();
        }
    }

    return 0;
}
