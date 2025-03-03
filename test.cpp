#include <bits/stdc++.h>
using namespace std;

#ifdef HoangHoangTuan
#include <debug.h>
#else
#define debug(...) 12
#endif

#define endl '\n'
#define int long long

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;

int N;
char a[MAXN];
vector<string> ans;

void push(int i)
{
    string s = "";
    int A = 0, B = 0, C = 0;
    for (int j = 1; j <= i; ++j) {
        s += a[j];
        if (a[j] == 'A')
            ++A;
        else if (a[j] == 'B')
            ++B;
        else
            ++C;
    }
    if (A >= B && B >= C && C > 0)
        ans.emplace_back(s);
}
void Try(int i)
{
    if (i > N)
        return;
    for (char j = 'A'; j <= 'C'; ++j) {
        a[i] = j;
        if (i >= 3)
            push(i);
        Try(i + 1);
    }
}
void hhtuann()
{
    cin >> N;
    Try(1);
    sort(ans.begin(), ans.end(), [&](string x, string y) { if(x.size() == y.size()) 
            return x < y; 
        return x.size() < y.size(); });
    for (auto x : ans)
        cout << x << endl;
    return;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }

    int testcase = 1;
    // cin >> testcase;
    while (testcase--)
        hhtuann();

    return 0;
}
/* Take Off Toward Your Dream ! */