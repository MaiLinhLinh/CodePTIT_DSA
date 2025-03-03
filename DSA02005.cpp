#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;
int n;
int a[100], f[100];
void in()
{
    for (int i = 1; i <= n; i++)
        cout << (char)(a[i] - 1 + 'A');
    cout << " ";
}
void Try(int i)
{
    for (int j = 1; j <= n; j++) {
        if (f[j] == 0) {
            f[j] = 1; // danh dau da xuat hien trong cau hinh hoan vi hien tai
            a[i] = j;
            if (i == n)
                in();
            else
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
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        n = s.size();
        Try(1);
        cout << "\n";
    }

    return 0;
}
