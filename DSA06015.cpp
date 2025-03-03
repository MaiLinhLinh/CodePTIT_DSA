#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;

// Tron 2 day con: day 1[l, m], day  2[m+1, r] xong roi cho day da tron quay ve mang a
void merge(int a[], int l, int m, int r)
{
    vector<int> x(a + l, a + m + 1); // vector x se copy day 1
    vector<int> y(a + m + 1, a + r + 1); // vector y se copy day 2
    int i = 0, j = 0;
    while (i < x.size() && j < y.size()) {
        if (x[i] <= y[j]) {
            a[l] = x[i];
            l++;
            i++;
        } else {
            a[l] = y[j];
            l++;
            j++;
        }
    }
    while (i < x.size()) {
        a[l] = x[i];
        l++;
        i++;
    }
    while (j < y.size()) {
        a[l] = y[j];
        l++;
        j++;
    }
}
void mergeSort(int a[], int l, int r)
{
    if (l >= r)
        return;
    int m = (l + r) / 2;
    mergeSort(a, l, m);
    mergeSort(a, m + 1, r);
    merge(a, l, m, r);
}

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
        for (int i = 0; i < n; i++)
            cin >> a[i];
        mergeSort(a, 0, n - 1);
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << "\n";
    }

    return 0;
}
