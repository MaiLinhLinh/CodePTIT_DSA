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
        string gray;
        cin >> gray;
        int bin[gray.size()];
        bin[0] = gray[0] - '0';
        for (int i = 1; i < gray.size(); i++) {
            int c = (gray[i] - '0') ^ bin[i - 1];
            bin[i] = c;
        }
        for (int i = 0; i < gray.size(); i++)
            cout << bin[i];
        cout << "\n";
    }

    return 0;
}
