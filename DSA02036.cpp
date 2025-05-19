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
int a[20], b[20];
vector<vector<int>> ans;
bool cmp(vector<int> a, vector<int> b)
{
    // sắp xếp theo thứ tự từ điển, dãy nào có phần tử bé hơn thì đứng trước
    for (int i = 0; i < min(a.size(), b.size()); i++) {
        if (a[i] != b[i])
            return a[i] < b[i];
    }
    // trong trường hợp lấy min độ dài 2 dãy và được kết quả 2 dãy bằng nhau thì so sánh tổng 2 dãy, dãy có tổng nhỏ hơn đứng trước
    int sumA = 0, sumB = 0;
    for (int i = 0; i < a.size(); i++)
        sumA += a[i];
    for (int i = 0; i < b.size(); i++)
        sumB += b[i];
    return sumA < sumB;
}

void Try(int i, int start, int currentSum)
{
    if (i > n)
        return;
    for (int j = start; j <= n; j++) {
        b[i] = a[j];
        currentSum += b[i];
        if (currentSum % 2 != 0) {
            vector<int> tmp;
            for (int k = 1; k <= i; k++)
                tmp.push_back(b[k]);
            sort(tmp.begin(), tmp.end(), greater<int>());
            ans.push_back(tmp);
        }
        Try(i + 1, j + 1, currentSum);
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
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        Try(1, 1, 0);
        sort(ans.begin(), ans.end(), cmp);
        for (int i = 0; i < ans.size(); i++) {
            for (int j = 0; j < ans[i].size(); j++) {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}
