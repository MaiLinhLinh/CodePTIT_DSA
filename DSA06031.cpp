#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int a[n + 1];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        // taoj 1 deque de luu cac gia tri cua doan k phan tu, voi dq.front la max
        deque<int> dq;

        // tao mang max voi maxRange[i] la max trong doan [ i - k + 1... i]
        int maxRange[n + 1];

        for (int i = 0; i < n; i++) {
            // khi ma cac phan tu o cuoi deque co gia tri <= a[i] thi bo di vi no khong the la max trong doan chua a[i]
            while (dq.size() && a[dq.back()] <= a[i])
                dq.pop_back();

            // Day phan tu thu i vao deque
            dq.push_back(i);
            // neu phan tu dau tien cua deque khong con thuoc doan k phan tu thi bo di
            if (dq.front() + k <= i)
                dq.pop_front();
            // khi trong deque co du k phan tu, thi lay max
            if (i >= k - 1)
                maxRange[i] = a[dq.front()];
        }
        for (int i = k - 1; i < n; i++)
            cout << maxRange[i] << " ";
        cout << "\n";
    }

    return 0;
}
