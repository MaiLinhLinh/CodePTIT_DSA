#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;
int n, k, a[100] = { 1 };
void in()
{
    for (int i = 1; i <= k; i++)
        cout << a[i] << " ";
    cout << "\n";
}
void Try(int i)
{
    for (int j = a[i - 1]; j <= n; j++) {
        a[i] = j;
        if (i == k)
            in();
        else
            Try(i + 1);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    Try(1);
    return 0;
}
