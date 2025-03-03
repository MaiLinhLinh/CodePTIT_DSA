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
vector<string> ans;

void push(int i)
{
    string s = "";
    int d0 = 0, d1 = 0, d2 = 0;
    for (int j = 1; j <= i; j++) {
        if (a[j] == 0) {
            s += "A";
            d0++;
        } else if (a[j] == 1) {
            s += "B";
            d1++;
        } else {
            s += "C";
            d2++;
        }
    }
    if (d0 > 0 && d1 > 0 && d2 > 0 && (d0 <= d1) && d1 <= d2)
        ans.push_back(s);
}

void Try(int i)
{
    if (i > n)
        return;
    for (int j = 0; j <= 2; j++) {
        a[i] = j;
        if (i >= 3) {
            push(i);
        }
        Try(i + 1);
    }
}

bool cmp(string a, string b)
{
    if (a.size() == b.size())
        return a < b;
    return a.size() < b.size();
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    Try(1);
    sort(ans.begin(), ans.end(), cmp);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << "\n";
    }
    return 0;
}
