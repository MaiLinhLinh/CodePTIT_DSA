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
/*
Tư tưởng: Sinh hoán vị cho n cột ( 1-> n), mỗi hàng lấy 1 cột tương ứng
ví dụ: hoán vị 2 1 3 thì hàng 1 lấy số cột 2, hàng 2 lấy số cột 1, hàng 3 lấy sô cột 3
các hoán vị không trùng nhau nên đảm bảo không trùng kết quả
=> ý tưởng cho các bài không trùng hàng, không trùng cột trong ma trận.
*/

int n, ok;
int a[15];
void sinh()
{
    int i = n - 1;
    while (i >= 1 && a[i] > a[i + 1])
        i--;
    if (i == 0)
        ok = 0;
    else {
        int j = n;
        while (j > i && a[j] < a[i])
            j--;
        swap(a[i], a[j]);
        int l = i + 1, r = n;
        while (l <= r) {
            swap(a[l], a[r]);
            l++;
            r--;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int k;
    cin >> n >> k;
    int c[n + 1][n + 1];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cin >> c[i][j];
    }
    vector<vector<int>> ans;
    for (int i = 1; i <= n; i++)
        a[i] = i;
    ok = 1;
    while (ok) {
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            sum += c[i][a[i]];
        }
        if (sum == k) {
            vector<int> tmp;
            for (int i = 1; i <= n; i++)
                tmp.push_back(a[i]);
            ans.push_back(tmp);
        }
        // for (int i = 1; i <= n; i++)
        //     cout << a[i] << " ";
        // cout << "\n";
        sinh();
    }
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << "\n";
    }

    return 0;
}
