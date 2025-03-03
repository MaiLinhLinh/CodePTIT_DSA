#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n + 1];
        set<int> se;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            se.insert(a[i]);
        }
        if (se.size() == 1)
            cout << "-1";
        else {
            int dem = 0;
            for (auto x : se) {
                cout << x << " ";
                dem++;
                if (dem == 2)
                    break;
            }
        }
        cout << "\n";
    }

    return 0;
}
