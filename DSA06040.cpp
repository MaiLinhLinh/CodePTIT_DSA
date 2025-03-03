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
        int n1, n2, n3;
        cin >> n1 >> n2 >> n3;
        ll a[n1 + 1], b[n2 + 1], c[n3 + 1];
        for (int i = 0; i < n1; i++)
            cin >> a[i];
        for (int i = 0; i < n2; i++)
            cin >> b[i];
        for (int i = 0; i < n3; i++)
            cin >> c[i];
        int l = 0, m = 0, n = 0;
        bool check = 0;
        // tim cac so bang nhau, neu a[i] < b[j] thi tang i len doi voi mang sap xep tang dan
        while (l < n1 && m < n2 && n < n3) {
            if (a[l] == b[m] && b[m] == c[n]) {
                check = 1;
                cout << a[l] << " ";
                l++;
                m++;
                n++;
            } else if (a[l] < b[m])
                l++;
            else if (b[m] < c[n])
                m++;
            else
                n++;
        }
        if (check == 0)
            cout << "-1";
        cout << "\n";
    }

    return 0;
}
