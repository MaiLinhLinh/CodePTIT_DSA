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
    int a[12];
    a[0] = 1;
    a[1] = 2;
    a[2] = 5;
    a[3] = 10;
    a[4] = 20;
    a[5] = 50;
    a[6] = 100;
    a[7] = 200;
    a[8] = 500;
    a[9] = 1000;
    while (t--) {
        int n;
        cin >> n;
        int num = 0;
        for (int i = 9; i >= 0; i--) {
            num += n / a[i];
            n = n % a[i];
            if (n == 0)
                break;
        }
        cout << num << "\n";
    }
    return 0;
}
