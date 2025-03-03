#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;
bool cmp(pair<int, int> p, pair<int, int> q)
{
    return p.first < q.first;
}

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
        int a[n + 1];
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            v[i] = { a[i], i + 1 };
        }
        // sắp xếp tăng dần theo giá trị a[i]
        sort(v.begin(), v.end(), cmp);

        ll res = -1e18;
        int last = v[0].second; // đây là vị trí i đầu tiên
        // for để tìm vị trí j thoả mãn j - i max
        for (int i = 1; i < n; i++) {
            if (v[i].second - last > res) { // nếu j - i > res
                res = v[i].second - last; // chỉ cập nhật res là khoảng cách giữa second và last hiện tại khi nó lớn hơn res
            }
            last = min(last, v[i].second); // cập nhật lại last sau mỗi bước; để luôn lấy được i nhỏ nhất
        }
        cout << res << "\n";
    }

    return 0;
}
