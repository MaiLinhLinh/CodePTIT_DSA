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
    int dem = 1;
    for (int i = 1; i < n; i++) {
        int check = 0;
        for (int j = 0; j < n - i; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                check = 1;
            }
        }
        if (check) {
            cout << "Buoc " << dem << ": ";
            dem++;
            for (int j = 0; j < n; j++)
                cout << a[j] << " ";
            cout << "\n";
        }
    }

    return 0;
}
