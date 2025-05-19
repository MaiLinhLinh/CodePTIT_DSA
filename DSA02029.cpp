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
void Try(char source, char helper, char target, int n)
{
    if (n == 1) {
        cout << source << " -> " << target << "\n";
        return;
    }
    Try(source, target, helper, n - 1);
    Try(source, helper, target, 1);
    Try(helper, source, target, n - 1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    Try('A', 'B', 'C', n);

    return 0;
}
