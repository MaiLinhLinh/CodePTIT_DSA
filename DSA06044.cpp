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
    vector<int> le;
    vector<int> chan;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (i % 2 == 0)
            chan.push_back(a[i]);
        else
            le.push_back(a[i]);
    }
    sort(le.begin(), le.end());
    sort(chan.begin(), chan.end(), greater<int>());
    int i = 0, j = 0;
    while (i < le.size() && j < chan.size()) {
        cout << le[i] << " " << chan[j] << " ";
        i++;
        j++;
    }
    if (i < le.size())
        cout << le[i] << " ";
    if (j < chan.size())
        cout << chan[i] << " ";
    return 0;
}
