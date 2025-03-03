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
    int n;
    cin >> n;
    int a[n + 1];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<vector<int>> v;
    vector<int> m;
    m.push_back(a[0]);
    v.push_back(m);
    int key, j;
    for (int i = 1; i < n; i++) {
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j -= 1;
        }
        a[j + 1] = key;
        vector<int> tmp;
        for (int j = 0; j <= i; j++)
            tmp.push_back(a[j]);
        v.push_back(tmp);
    }
    for (int i = v.size(); i >= 2; i--) {
        cout << "Buoc " << i - 1 << ": ";
        for (int j = 0; j < v[i - 1].size(); j++)
            cout << v[i - 1][j] << " ";
        cout << "\n";
    }
    cout << "Buoc 0: " << v[0][0] << "\n";

    return 0;
}
