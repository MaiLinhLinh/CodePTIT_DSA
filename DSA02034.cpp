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
int n;
int a[15];
bool visited[15];
void in()
{
    for (int i = 1; i <= n; i++)
        cout << a[i];
    cout << "\n";
}
bool check()
{
    for (int i = 2; i < n; i++) {
        if (abs(a[i] - a[i - 1]) == 1 || abs(a[i] - a[i + 1]) == 1)
            return 0;
    }
    return 1;
}

void Try(int i)
{
    for (int j = 1; j <= n; j++) {
        if (!visited[j]) {
            visited[j] = 1;
            a[i] = j;
            if (i == n && check())
                in();
            else
                Try(i + 1);
            visited[j] = 0;
        }
    }
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
        Try(1);
    }

    return 0;
}
