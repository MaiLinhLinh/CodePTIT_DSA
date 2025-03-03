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

void Try(int n, vector<int>& tmp)
{
    if (n < 1)
        return;
    vector<int> v(n - 1);
    for (int i = 0; i < n - 1; i++)
        v[i] = tmp[i] + tmp[i + 1];
    Try(n - 1, v);
    cout << "[";
    for (int i = 0; i < n - 1; i++)
        cout << tmp[i] << " ";
    cout << tmp[n - 1] << "] ";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Try(n, a);
        cout << "\n";
    }

    return 0;
}
