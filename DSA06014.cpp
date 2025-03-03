#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;
bool isPrime(int n)
{
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return 0;
    }
    return n > 1;
}

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
        int check = 0;
        for (int i = 2; i + i <= n; i++) {
            if (isPrime(i)) {
                if (isPrime(n - i)) {
                    if (i <= n - i)
                        cout << i << " " << n - i << "\n";
                    else
                        cout << n - i << " " << i << "\n";
                    check = 1;
                    break;
                }
            }
        }
        if (check == 0)
            cout << "-1\n";
    }

    return 0;
}
