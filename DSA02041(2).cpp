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
vector<int> ans;
void Try(int n, int cnt)
{
    if (n == 1) {
        ans.push_back(cnt);
        return;
    }
    Try(n - 1, cnt + 1);
    if (n % 2 == 0)
        Try(n / 2, cnt + 1);
    if (n % 3 == 0)
        Try(n / 3, cnt + 1);
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
        Try(n, 0);
        sort(ans.begin(), ans.end());
        cout << ans[0] << "\n";
    }

    return 0;
}
