#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;
int n, k;
int b[1005];
void sinh()
{
    int i = k;
    while (i >= 1 && b[i] == (n - k + i)) {
        i--;
    }
    b[i] = i > 0 ? b[i] + 1 : 0;
    for (int j = i + 1; j <= k; j++)
        b[j] = b[j - 1] + 1;
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
        for (int i = 1; i <= k; i++)
            cin >> b[i];
        sinh();
        for (int i = 1; i <= k; i++)
            cout << b[i] << " ";
        cout << "\n";
    }

    return 0;
}
