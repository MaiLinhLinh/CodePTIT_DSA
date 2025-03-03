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
int n, k;
int a[105], b[105];
vector<vector<int>> ans;

void Try(int i, int start, int currentSum)
{
    for (int j = start; j <= n; j++) {
        b[i] = a[j];
        currentSum += b[i];
        if (currentSum == k) {
            vector<int> tmp;
            for (int h = 1; h <= i; h++)
                tmp.push_back(b[h]);
            ans.push_back(tmp);
        } else if (currentSum < k)
            Try(i + 1, j + 1, currentSum); // j+1 vì không được lặp số.số tiếp theo sẽ bắt đầu từ phần tử a[j+1].
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
        cin >> n >> k;
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
                cout << ans[i][ans[i].size() - 1] << "] ";
            }
        }
        cout << "\n";
    }

    return 0;
}
