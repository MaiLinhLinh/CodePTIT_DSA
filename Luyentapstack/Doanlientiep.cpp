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
        int n;
        cin >> n;
        int a[n + 1];
        int resmax[n + 1];
        int resmin[n + 1];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        stack<int> stmin;
        stack<int> stmax;
        // for (int i = n - 1; i >= 0; i--) {
        //     if (!stmax.empty() && a[i] >= a[stmax.top()])
        //         stmax.pop();
        //     if (stmax.empty())
        //         resmax[i] = n - 1;
        //     else
        //         resmax[i] = stmax.top();
        //     stmax.push(i);
        // }
        for (int i = 0; i < n; i++) {
            while (!stmax.empty() && a[i] >= a[stmax.top()])
                stmax.pop();
            if (stmax.empty())
                resmax[i] = 0;
            else
                resmax[i] = stmax.top();
            stmax.push(i);
        }
        for (int i = 0; i < n; i++)
            cout << resmax[i] << " ";
        cout << "\n";

        for (int i = 0; i < n; i++) {
            while (!stmin.empty() && a[i] < a[stmin.top()])
                stmin.pop();
            if (stmin.empty())
                resmin[i] = 0;
            else
                resmin[i] = stmin.top();
            stmin.push(i);
        }
        // for (int i = 0; i < n; i++)
        //     cout << resmax[i] << " ";
        // cout << "\n";
        // for (int i = 0; i < n; i++)
        //     cout << a[resmin[i]] << " ";
        // cout << "\n";
        // for (int i = 0; i < n; i++)
        //     cout << resmax[i] - resmin[i] + 1 << " ";
        // cout << "\n";
    }
    return 0;
}
