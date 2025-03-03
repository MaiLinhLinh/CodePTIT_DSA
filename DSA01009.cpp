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
int n, k, ok;
int a[20];
void sinh()
{
    int i = n;
    while (i >= 1 && a[i] == 1) {
        a[i] = 0;
        i--;
    }
    if (i == 0)
        ok = 0;
    else
        a[i] = 1;
}
bool check()
{
    int dem = 0;
    int soday = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == 0)
            dem++;
        else {
            if (dem == k)
                soday++;
            dem = 0;
        }
    }
    if (dem == k)
        soday++;
    return soday == 1;
}

vector<vector<string>> v(nmax);
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    ok = 1;
    for (int i = 1; i <= n; i++)
        a[i] = 0;
    int cnt = 0;
    while (ok) {
        if (check()) {
            cnt++;
            for (int i = 1; i <= n; i++) {
                if (a[i] == 0)
                    v[cnt].push_back("A");
                else
                    v[cnt].push_back("B");
            }
        }
        sinh();
    }
    cout << cnt << "\n";
    for (int i = 1; i <= cnt; i++) {
        for (int j = 0; j < v[i].size(); j++)
            cout << v[i][j];
        cout << "\n";
    }

    return 0;
}
