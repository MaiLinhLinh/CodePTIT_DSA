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

int xy[10][10] = { { -2, -1 }, { -2, 1 }, { -1, -2 }, { 1, -2 }, { -1, 2 }, { 2, -1 }, { 1, 2 }, { 2, 1 } };
struct Node {
    int step, x, y;
    Node(int step, int x, int y)
    {
        this->step = step;
        this->x = x;
        this->y = y;
    }

    bool operator<(Node other) const
    {
        return this->step > other.step;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string st, en;
        cin >> st >> en;
        int y1 = st[0] - 'a' + 1;
        int x1 = st[1] - '0';
        int y2 = en[0] - 'a' + 1;
        int x2 = en[1] - '0';
        // cout << x1 << " " << y1 << " " << x2 << " " << y2 << "\n";

        priority_queue<Node> pq;
        pq.push(Node(0, x1, y1));
        bool visited[10][10] = { 0 };
        while (!pq.empty()) {
            auto [step, x, y] = pq.top();
            pq.pop();
            if (x == x2 && y == y2) {
                cout << step << "\n";
                break;
            } else {
                for (int i = 0; i < 8; i++) {
                    if (x + xy[i][0] >= 1 && x + xy[i][0] <= 8 && y + xy[i][1] >= 1 && y + xy[i][1] <= 8 && !visited[x + xy[i][0]][y + xy[i][1]]) {
                        pq.push(Node(step + 1, x + xy[i][0], y + xy[i][1]));
                        visited[x + xy[i][0]][y + xy[i][1]] = 1;
                    }
                }
            }
        }
    }

    return 0;
}
