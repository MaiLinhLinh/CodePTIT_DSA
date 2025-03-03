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
int n, s, p;
bool prime[nmax];
vector<int> nto;
void sang()
{
    prime[0] = prime[1] = 1; // khong la so nguyen to
    for (int i = 2; i * i <= nmax; i++) {
        if (!prime[i]) {
            for (int j = i * i; j <= nmax; j += i)
                prime[j] = 1;
        }
    }
    for (int i = 2; i <= nmax; i++) {
        if (!prime[i])
            nto.push_back(i);
    }
}
bool visited[nmax];
int a[20];
vector<vector<int>> ans;
void Try(int i, int start, int currentSum)
{
    for (int j = start; j <= 60; j++) {
        if (!visited[nto[j]]) {
            visited[nto[j]] = 1;
            a[i] = nto[j];
            currentSum += nto[j];
            if (currentSum == s && i == n) {
                vector<int> tmp;
                for (int i = 1; i <= n; i++)
                    tmp.push_back(a[i]);
                ans.push_back(tmp);
            } else if (currentSum < s && i < n)
                Try(i + 1, j, currentSum);
            visited[nto[j]] = 0;
            currentSum -= nto[j];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    sang();
    // for (int i = 0; i < 10; i++)
    //     cout << nto[i] << " ";
    int t;
    cin >> t;
    while (t--) {
        ans.clear();
        cin >> n >> p >> s;
        int pos;
        for (int i = 0; i <= 60; i++) {
            if (nto[i] > p) {
                pos = i;
                break;
            }
        }
        Try(1, pos, 0);
        cout << ans.size() << "\n";
        for (int i = 0; i < ans.size(); i++) {
            for (int j = 0; j < ans[i].size(); j++)
                cout << ans[i][j] << " ";
            cout << '\n';
        }
    }

    return 0;
}
