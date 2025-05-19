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
int n, k, ok;
int a[20];
void sinh(int n)
{
    int i = k;
    while (i >= 1 && a[i] == n - k + i)
        i--;
    if (i == 0)
        ok = 0;
    else {
        a[i]++;
        int j = i + 1;
        while (j <= k) {
            a[j] = a[j - 1] + 1;
            j++;
        }
    }
}
int sochuso(int x)
{
    int dem = 0;
    while (x) {
        dem++;
        x /= 10;
    }
    return dem;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= k; i++)
        a[i] = i;
    int b[n + 1];
    set<ll> se;
    vector<int> v;
    map<int, int> mp;
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        if (!mp.count(b[i])) {
            v.push_back(b[i]);
        }
        mp[b[i]] = 1;
    }
    int m = v.size();
    cout << n << "\n";
    ok = 1;
    while (ok) {
        ll num = 0;
        for (int i = 1; i <= k; i++)
            num = 1ll * num * pow(10, sochuso(v[a[i]])) + v[a[i]];
        se.insert(num);
        sinh(m);
    }
    for (auto x : se)
        cout << x << "\n";

    return 0;
}
