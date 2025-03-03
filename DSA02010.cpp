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
int n, X;
int a[30];
int b[30];
vector<vector<int>> ans;
void Try(int i, int start, int currentSum) // duyệt chỉ số bắt đầu từ vị trí đang xét đổ về sau để đảm bảo không bị quay ngược lại chọn giá trị cũ, khiến lặp tổ hợp
{
    for (int j = start; j <= n; j++) {
        b[i] = a[j];
        currentSum += b[i];
        if (currentSum == X) {
            vector<int> tmp;
            for (int k = 1; k <= i; k++)
                tmp.push_back(b[k]);
            ans.push_back(tmp);
        } else if (currentSum < X)
            Try(i + 1, j, currentSum);
        currentSum -= b[i];
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
        ans.clear();
        cin >> n >> X;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        sort(a + 1, a + n + 1);
        Try(1, 1, 0);
        if (ans.size() == 0)
            cout << "-1";
        else {
            for (int i = 0; i < ans.size(); i++) {
                cout << "[";
                for (int j = 0; j < ans[i].size() - 1; j++)
                    cout << ans[i][j] << " ";
                cout << ans[i][ans[i].size() - 1] << "]";
            }
        }
        cout << "\n";
    }

    return 0;
}
