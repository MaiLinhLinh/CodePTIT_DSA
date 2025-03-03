#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;
int n, ok;
int b[1005];
void sinh()
{
    int i = n;
    while (i >= 1 && b[i] == 1) {
        b[i] = 0;
        i--;
    }
    // if (i == 0)
    //     ok = 0;
    // else
    b[i] = 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string a;
        cin >> a;
        n = a.size();
        for (int i = 1; i <= n; i++) {
            b[i] = (a[i - 1] - '0');
        }
        ok = 1;
        sinh();
        // if (ok == 0) {
        //     for (int i = 1; i <= n; i++)
        //         b[i] = 0;
        // }
        for (int i = 1; i <= n; i++)
            cout << b[i];
        cout << "\n";
    }

    return 0;
}
