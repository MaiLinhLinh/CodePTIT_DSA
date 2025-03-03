#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;
// de dao nguoc thanh 1 xau tang dan với xâu con được đảo phải là xâu con ở giữa, thì:
// vi du gia trị:  1 2 3 4 5   thì số 2 phai ở vị trí 2 hoặc ở vị trí 4. Còn nếu 2 ở vị trí khác thì khi lật ngược mảng chứa 2 thì nó ko bao giờ quay về vị trí thứ 2 được.
// vị trí:         1 2 3 4 5
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n + 2], b[n + 2];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            b[i] = a[i];
        }
        sort(b, b + n);
        int check = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] != b[i] && a[i] != b[n - 1 - i]) {
                check = 1;
                break;
            }
        }
        if (check == 0)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}
