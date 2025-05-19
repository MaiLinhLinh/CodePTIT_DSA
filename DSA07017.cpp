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
        int tmp[n + 1];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        stack<int> st;
        // lưu chỉ số phần tử bên phải lớn hơn phần tử vị trí i
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && a[i] >= a[st.top()])
                st.pop();
            if (st.empty())
                tmp[i] = -1;
            else
                tmp[i] = st.top();
            st.push(i);
        }

        while (!st.empty()) {
            st.pop();
        }
        int nes[n + 1];
        // lưu chỉ số phần tử bên phải nhỏ hơn phần tử vị trí i
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && a[i] <= a[st.top()])
                st.pop();
            if (st.empty())
                nes[i] = -1;
            else
                nes[i] = st.top();
            st.push(i);
        }

        for (int i = 0; i < n; i++) {
            int x = tmp[i]; // chỉ số phần tử bên phải lớn hơn phần tử vị trí i
            if (x == -1 || nes[x] == -1) // nes[x] // chỉ số phần tử bên phải nhỏ hơn phần tử vị trí x
                cout << "-1 ";
            else {
                cout << a[nes[x]] << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}
