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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string bin;
        cin >> bin;
        char gray[bin.size()];
        gray[0] = bin[0];
        for (int i = 1; i < bin.size(); i++) {
            int c = (bin[i] - '0') ^ (bin[i - 1] - '0');
            gray[i] = c + '0';
        }
        for (int i = 0; i < bin.size(); i++)
            cout << gray[i];
        cout << "\n";
    }

    return 0;
}
