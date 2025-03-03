#include <bits/stdc++.h>
using namespace std;
#ifdef MaiLinh
#include <debug.h>
#else
#define debug(...) 12
#endif
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
int n, k;
int a[100];
void in()
{
    for (int i = 1; i <= k; i++)
        cout << (char)(a[i] - 1 + 'A');

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
    char c;
    cin >> c >> k;
    n = c - 'A' + 1;
    a[0] = 1;

    Try(1);
    return 0;
}
