#include <bits/stdc++.h>
using namespace std;
#ifdef MaiLinh
#include <debug.h>
#else
#define debug(...) 12
#endif
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e4 + 7)

int n;
int a[nmax];

void inOrder(int i)
{
    if (i >= n)
        return;
    inOrder(i * 2 + 1);
    cout << a[i] << " ";
    inOrder(i * 2 + 2);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        inOrder(0);
        cout << "\n";
    }

    return 0;
}
