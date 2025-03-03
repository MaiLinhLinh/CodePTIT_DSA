#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;
int n, m, a[100], f[100];
void in()
{
    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
    cout << "\n";
}
void Try(int i)
{
    for (int j = 1; j <= n; j++) { // moi vi tri i co n kha nang
        if (f[j] == 0) {
            f[j] = 1; // danh dau so da xuat hien trong hoan vi
            a[i] = j;
            if (i == n) {
                if (a[n] == m)
                    in();
            } else
                Try(i + 1);
            f[j] = 0; // backtrack
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    Try(1);
    return 0;
}
