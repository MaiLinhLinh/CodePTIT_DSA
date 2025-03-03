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
        for (int i = 0; i < n; i++)
            cin >> a[i];
        vector<vector<int>> v;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (a[i] > a[j])
                    swap(a[i], a[j]);
            }
            vector<int> tmp;
            for (int j = 0; j < n; j++) {
                tmp.push_back(a[j]);
            }
            v.push_back(tmp);
        }
        for (int i = v.size() - 1; i >= 0; i--) {
            cout << "Buoc " << i + 1 << ": ";
            for (int j = 0; j < v[i].size(); j++) {
                cout << v[i][j] << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}
