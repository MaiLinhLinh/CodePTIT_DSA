#include <bits/stdc++.h>
using namespace std;

#define ll long long

int n, w;
int a[105], c[105];
int x[105];
int currentValue = 0, remainedValue;
ll fotp = -1e18;
vector<int> ans;

void Try(int i)
{
    for (int j = c[i] / a[i]; j >= 0; j--) { // Duyệt từ giá trị lớn nhất
        x[i] = j;
        currentValue += c[i] * x[i];
        remainedValue -= a[i] * x[i];

        if (i == n) {
            if (currentValue > fotp) {
                fotp = currentValue;
                ans.clear();
                for (int k = 1; k <= n; k++)
                    ans.push_back(x[k]);
            }
        } else {
            // Nhánh cận với hàm đánh giá
            double upperBound = currentValue;
            int tempWeight = remainedValue;
            for (int j = i + 1; j <= n && tempWeight > 0; j++) {
                if (a[j] <= tempWeight) {
                    upperBound += c[j];
                    tempWeight -= a[j];
                } else {
                    upperBound += c[j] * (1.0 * tempWeight / a[j]);
                    break;
                }
            }

            if (upperBound > fotp && remainedValue >= 0)
                Try(i + 1);
        }

        currentValue -= c[i] * x[i];
        remainedValue += a[i] * x[i];
    }
}

bool cmp(pair<int, int> p, pair<int, int> q)
{
    return (1.0 * p.first / p.second) > (1.0 * q.first / q.second);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> w;
    remainedValue = w;
    vector<pair<int, int>> pii(n);

    for (int i = 1; i <= n; i++) {
        cin >> c[i];
        pii[i - 1].first = c[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pii[i - 1].second = a[i];
    }

    sort(pii.begin(), pii.end(), cmp);

    for (int i = 1; i <= n; i++) {
        c[i] = pii[i - 1].first;
        a[i] = pii[i - 1].second;
    }

    Try(1);

    cout << fotp << "\n";
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";

    return 0;
}
