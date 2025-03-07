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
int a[25];
int b[25];

bool check()
{
    vector<int> tmp;
    for (int i = 1; i <= n; i++) {
        if (a[i] == 1)
            tmp.push_back(b[i]);
    }
    if (tmp.size() < 2)
        return 0;
    for (int i = 1; i < tmp.size(); i++) {
        if (tmp[i] <= tmp[i - 1])
            return 0;
    }
    return 1;
}

void Try(int i)
{
    for (int j = 0; j <= 1; j++) {
        a[i] = j;
        if (i == n && check()) {
            for (int i = 1; i <= n; i++)
                cout << a[i] << " ";
            cout << "\n";
            for (int i = 1; i <= n; i++) {
                if (a[i] == 1)
                    cout << b[i] << " ";
            }
            cout << "\n";

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
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    Try(1);

    return 0;
}
