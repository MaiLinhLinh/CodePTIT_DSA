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
int a[20];
bool visited[20];

void in()
{
    for (int i = 1; i <= n; i++)
        cout << (char)(a[i] - 1 + 'A');
    cout << "\n";
}
bool check()
{
    int b[15];
    for (int i = 1; i <= n; i++) {
        if (a[i] == 1 || a[i] == 5)
            b[i] = 1;
        else
            b[i] = 0;
    }
    for (int i = 2; i < n; i++) {
        if (b[i] == 1 && b[i - 1] == 0 && b[i + 1] == 0)
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
            if (i == n && check()) {
                in();
            } else
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
    char c;
    cin >> c;
    n = c - 'A' + 1;
    Try(1);

    return 0;
}
