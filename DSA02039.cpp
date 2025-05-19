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

int n;
int a[15];
vector<vector<int>> ans;
void Try(int i, int currentSum)
{
    for (int j = a[i - 1]; j >= 1; j--) {
        a[i] = j;
        currentSum += a[i];
        if (currentSum == n) {
            vector<int> tmp;
            for (int k = 1; k <= i; k++)
                tmp.push_back(a[k]);
            ans.push_back(tmp);
        } else if (currentSum < n)
            Try(i + 1, currentSum);
        currentSum -= a[i];
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
        cin >> n;
        a[0] = n;
        Try(1, 0);
        cout << ans.size() << "\n";
        for (int i = 0; i < ans.size(); i++) {
            cout << "(";
            for (int j = 0; j < ans[i].size() - 1; j++)
                cout << ans[i][j] << " ";
            cout << ans[i][ans[i].size() - 1] << ") ";
        }
        cout << "\n";
    }

    return 0;
}
