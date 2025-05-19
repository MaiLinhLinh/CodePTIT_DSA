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
        int S, T;
        cin >> S >> T;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        // first la so lan bien doi, second la ket qua bien doi
        pq.push({ 0, S });
        bool visited[20005] = { 0 };

        while (!pq.empty()) {
            auto [step, num] = pq.top();
            pq.pop();
            if (num == T) {
                cout << step << "\n";
                break;
            } else {
                if (num - 1 >= 0 && !visited[num - 1]) {
                    pq.push({ step + 1, num - 1 });
                    visited[num - 1] = 1;
                }
                if (num * 2 < 20005 && !visited[num * 2]) {
                    pq.push({ step + 1, num * 2 });
                    visited[num * 2] = 1;
                }
            }
        }
    }

    return 0;
}
