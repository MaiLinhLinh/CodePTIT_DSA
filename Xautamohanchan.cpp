#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;
int n;
int a[15];
void in()
{
    for (int i = 1; i <= n; i++)
        cout << a[i];
    cout << "\n";
}
int d = 1;
void Try(int i)
{
    for (int j = 0; j <= 2; j++) {
        a[i] = j;
        if (i == n) {
            if (d % 2 == 0) {
                cout << d << ": ";
                in();
            }
            d++;
        } else
            Try(i + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    Try(1);

    return 0;
}
