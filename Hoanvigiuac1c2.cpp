#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;
int n, m, a[100], f[100];
void in()
{
    for (int i = 1; i <= m - n + 1; i++)
        cout << (char)(a[i] - 1 + 'A');
    cout << "\n";
}
void Try(int i)
{
    for (int j = n; j <= m; j++) { // moi vi tri i co m - n + 1 kha nang
        if (f[j] == 0) {
            a[i] = j;
            if (i == m - n + 1) {
                in();
            } else {
                f[j] = 1; // danh dau so da xuat hien trong hoan vi
                Try(i + 1);
                f[j] = 0; // backtrack
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    char c1, c2;
    cin >> c1 >> c2;
    if (c1 > c2)
        swap(c1, c2);
    n = c1 - 'A' + 1;
    m = c2 - 'A' + 1;
    Try(1);
    return 0;
}
