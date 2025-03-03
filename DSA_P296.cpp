#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;

int n, q;
int a[100005];
ll prefix[100005];
void PrefixSum()
{
    prefix[0] = 0;
    for (int i = 1; i <= 100003; i++) {
        prefix[i] = prefix[i - 1];
        if (a[i] > 0)
            prefix[i] += a[i];
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    PrefixSum();
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << prefix[r] - prefix[l - 1] << "\n";
    }
    return 0;
}
