#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;
int n, k, ok;
int a[50];
void sinh()
{
    int i = k;
    while (i >= 1 && a[i] == (n - k + i))
        i--;
    if (i == 0)
        ok = 0;
    else {
        a[i]++;
        for (int j = i + 1; j <= k; j++)
            a[j] = a[j - 1] + 1;
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
        cin >> n >> k;
        map<int, int> mp;
        for (int i = 1; i <= k; i++) {
            cin >> a[i];
            mp[a[i]]++;
        }
        ok = 1;
        sinh();
        if (ok == 0)
            cout << k << "\n";
        else {
            int cnt = 0;
            for (int i = 1; i <= k; i++) {
                if (mp.count(a[i]))
                    cnt++;
            }
            cout << k - cnt << "\n";
        }
    }

    return 0;
}
