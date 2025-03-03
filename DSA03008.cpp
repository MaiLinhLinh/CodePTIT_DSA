#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;

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
        int s[n + 2], f[n + 2];
        for (int i = 1; i <= n; i++)
            cin >> s[i];
        for (int i = 1; i <= n; i++)
            cin >> f[i];
        pair<int, int> pii[n + 2];
        for (int i = 1; i <= n; i++) {
            pii[i] = { f[i], s[i] };
        }
        sort(pii + 1, pii + n + 1); // sắp xếp tăng dần theo thời gian kết thúc công việc, kết thúc sớm thì được nhiều cv hơn
        int ans = 1, finish = pii[1].first; // khi thời gian bắt đầu của hành động 4 mà lớn hơn thời gian kết thúc của hành động 2 thì nó cx lớn hơn tg kết thúc hành động 1. Khi nó nếu tg bắt đầu hành động 2 bé hơn tg kết thúc hành động 1 thì chuỗi hành động bắt đầu từ hành động 2 cx có số lượng hành động bằng chuỗi hành động bắt đầu từ hành động 1 và bỏ qua hành động 2.
        for (int i = 2; i <= n; i++) {
            if (pii[i].second >= finish) {
                ans++;
                finish = pii[i].first;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
