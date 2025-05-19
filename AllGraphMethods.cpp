#include <algorithm>
#include <climits>
#include <functional>
#include <iostream>
#include <queue>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

#ifdef MaiLinh
#include <debug.h>
#else
#define debug(...) 12
#endif

#define endl '\n'
#define LL long long
#define fi first
#define se second
// #define int LL

const string NAME = "HoangHoangTuan";
const bool USING_FILE = false;
const bool USING_TESTCASE = false;

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;

class Graph {
private:
    vector<vector<int>> adjMatrix;
    vector<int> degree, inDegree, outDegree;
    int size;
    bool isDirected, isWeighted, isNegative;

public:
    Graph(int n = 0)
    {
        size = n;
        adjMatrix.resize(n + 1, vector<int>(n + 1, 0));
        degree.resize(n + 1, 0);
        inDegree.resize(n + 1, 0);
        outDegree.resize(n + 1, 0);
        isDirected = isWeighted = false;
    }

    Graph(const vector<vector<int>>& matrix)
    {
        size = matrix.size() - 1;
        adjMatrix = matrix;
        isDirected = isDirectedGraph(matrix);
        isWeighted = isWeightedGraph(matrix);
        isNegative = isNegativeGraph(matrix);
        degree.resize(size + 1, 0);
        inDegree.resize(size + 1, 0);
        outDegree.resize(size + 1, 0);
        for (int u = 1; u <= size; ++u) {
            for (int v = 1; v <= size; ++v) {
                if (matrix[u][v]) {
                    ++outDegree[u];
                    ++inDegree[v];
                    ++degree[u];
                }
            }
        }
    }

    void print(const vector<vector<int>>& matrix = {})
    {
        const vector<vector<int>>& newMatrix = (matrix.empty() ? adjMatrix : matrix);
        int N = newMatrix.size() - 1;
        for (int u = 1; u <= N; ++u) {
            for (int v = 1; v <= N; ++v) {
                cout << newMatrix[u][v] << " ";
            }
            cout << endl;
        }
    }

    bool isDirectedGraph(const vector<vector<int>>& matrix = {})
    {
        const vector<vector<int>>& newMatrix = (matrix.empty() ? adjMatrix : matrix);
        int N = newMatrix.size() - 1;
        for (int u = 1; u <= N; ++u)
            for (int v = 1; v <= N; ++v)
                if (newMatrix[u][v] != newMatrix[v][u])
                    return true;
        return false;
    }

    bool isWeightedGraph(const vector<vector<int>>& matrix = {})
    {
        const vector<vector<int>>& newMatrix = (matrix.empty() ? adjMatrix : matrix);
        int N = newMatrix.size() - 1;
        for (int u = 1; u <= N; ++u)
            for (int v = 1; v <= N; ++v)
                if (newMatrix[u][v] != 1 && newMatrix[u][v] != 0)
                    return true;
        return false;
    }

    bool isNegativeGraph(const vector<vector<int>>& matrix = {})
    {
        const vector<vector<int>>& newMatrix = (matrix.empty() ? adjMatrix : matrix);
        int N = newMatrix.size() - 1;
        for (int u = 1; u <= N; ++u)
            for (int v = 1; v <= N; ++v)
                if (newMatrix[u][v] < 0)
                    return true;
        return false;
    }

    /* FOR ALL GRAPH TYPES */
    void BFS(int u, vector<bool>& visited, const vector<vector<int>>& matrix = {})
    {
        const vector<vector<int>>& newMatrix = (matrix.empty() ? adjMatrix : matrix);
        int N = newMatrix.size() - 1;
        queue<int> q;
        visited[u] = true;
        q.push(u);
        while (!q.empty()) {
            u = q.front();
            q.pop();
            for (int v = 1; v <= N; ++v) {
                if (newMatrix[u][v] && !visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
    }

    vector<int> getBFSPath(int start)
    {
        vector<int> path;
        vector<bool> visited(size + 1, false);
        queue<int> q;
        visited[start] = true;
        q.push(start);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            path.push_back(u);
            for (int v = 1; v <= size; ++v) {
                if (adjMatrix[u][v] && !visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        return path;
    }

    vector<int> getBFSPath(int start, int finish)
    {
        vector<int> path, parents(size + 1, -1);
        vector<bool> visited(size + 1, false);
        queue<int> q;
        visited[start] = true;
        q.push(start);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            path.push_back(u);
            for (int v = 1; v <= size; ++v) {
                if (adjMatrix[u][v] && !visited[v]) {
                    visited[v] = true;
                    parents[v] = u;
                    q.push(v);
                }
            }
        }
        if (!visited[finish])
            return {};
        for (int v = finish; v != -1; v = parents[v])
            path.push_back(v);
        reverse(path.begin(), path.end());
        return path;
    }

    void DFS(int start, vector<bool>& visited, const vector<vector<int>>& matrix = {})
    {
        const vector<vector<int>>& newMatrix = (matrix.empty() ? adjMatrix : matrix);
        int N = newMatrix.size() - 1;
        function<void(int)> dfs = [&](int u) -> void {
            visited[u] = true;
            for (int v = 1; v <= N; ++v) {
                if (newMatrix[u][v] && !visited[v])
                    dfs(v);
            }
        };
        dfs(start);
    }

    vector<int> getDFSPath(int start)
    {
        vector<int> path;
        vector<bool> visited(size + 1, false);
        function<void(int)> dfs = [&](int u) -> void {
            visited[u] = true;
            path.push_back(u);
            for (int v = 1; v <= size; ++v) {
                if (adjMatrix[u][v] && !visited[v])
                    dfs(v);
            }
        };
        dfs(start);
        return path;
    }

    vector<int> getDFSPath(int start, int finish)
    {
        vector<int> path, parents(size + 1, -1);
        vector<bool> visited(size + 1, false);
        function<void(int)> dfs = [&](int u) -> void {
            visited[u] = true;
            path.push_back(u);
            for (int v = 1; v <= size; ++v) {
                if (adjMatrix[u][v] && !visited[v]) {
                    parents[v] = u;
                    dfs(v);
                }
            }
        };
        if (!visited[finish])
            return {};
        for (int v = finish; v != -1; v = parents[v])
            path.push_back(v);
        reverse(path.begin(), path.end());
        return path;
    }

    bool isEulerianGraph()
    {
        if (!isDirected) {
            if (!isConnectedGraph())
                return false;
            for (int u = 1; u <= size; ++u) {
                if (degree[u] % 2 != 0)
                    return false;
            }
            return true;
        } else {
            if (!isStronglyConnectedGraph())
                return false;
            for (int u = 1; u <= size; ++u) {
                if (inDegree[u] != outDegree[u])
                    return false;
            }
            return true;
        }
    }

    bool isSemiEulerianGraph()
    {
        if (!isDirected) {
            if (!isConnectedGraph() || isEulerianGraph())
                return false;
            int oddCount = 0;
            for (int u = 1; u <= size; ++u)
                oddCount += (degree[u] % 2);
            return (oddCount == 2);
        } else {
            if (!isStronglyConnectedGraph())
                return false;
            if (isEulerianGraph())
                return false;
            int start = 0, end = 0;
            for (int u = 1; u <= size; ++u) {
                if (outDegree[u] - inDegree[u] == 1)
                    ++start;
                else if (inDegree[u] - outDegree[u] == 1)
                    ++end;
                else if (inDegree[u] != outDegree[u])
                    return false;
            }
            return (start == 1 && end == 1);
        }
    }

    vector<int> eulerianPath(int start)
    {
        if (!isEulerianGraph() && !isSemiEulerianGraph())
            return {};
        vector<int> path;
        stack<int> st;
        vector<vector<int>> newMatrix = adjMatrix;
        st.push(start);
        while (!st.empty()) {
            int u = st.top();
            bool check = false;

            for (int v = 1; v <= size; ++v) {
                if (newMatrix[u][v]) {
                    check = true;
                    newMatrix[u][v] = newMatrix[v][u] = 0;
                    st.push(v);
                    break;
                }
            }
            if (!check) {
                path.push_back(u);
                st.pop();
            }
        }
        reverse(path.begin(), path.end());
        return path;
    }

    vector<vector<int>> hamiltonianPath(int start)
    {
        vector<vector<int>> pathList;
        vector<int> path = { start };
        vector<bool> visited(size + 1, false);
        function<void(int)> hmt = [&](int i) -> void {
            for (int v = 1; v <= size; ++v) {
                if (adjMatrix[path.back()][v]) {
                    if (!visited[v]) {
                        visited[v] = true;
                        path.push_back(v);
                        if (i == size)
                            pathList.push_back(path);
                        else
                            hmt(i + 1);
                        visited[v] = false;
                        path.pop_back();
                    }
                }
            }
        };
        visited[start] = true;
        hmt(2);
        return pathList;
    }

    vector<vector<int>> hamiltonianCycle(int start)
    {
        vector<vector<int>> cycleList;
        vector<int> cycle = { start };
        vector<bool> visited(size + 1, false);
        function<void(int)> hmt = [&](int i) -> void {
            for (int v = 1; v <= size; ++v) {
                if (adjMatrix[cycle.back()][v]) {
                    if (i == size + 1 && v == start) {
                        cycle.push_back(v);
                        cycleList.push_back(cycle);
                        cycle.pop_back();
                    } else if (!visited[v]) {
                        visited[v] = true;
                        cycle.push_back(v);
                        hmt(i + 1);
                        visited[v] = false;
                        cycle.pop_back();
                    }
                }
            }
        };
        visited[start] = true;
        hmt(2);
        return cycleList;
    }

    vector<vector<int>> dijkstraPath(int start)
    {
        vector<vector<int>> paths(size + 1);
        vector<int> dist(size + 1, INF), parents(size + 1, -1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        dist[start] = 0;
        pq.push({ 0, start });
        while (!pq.empty()) {
            auto [curDist, u] = pq.top();
            pq.pop();
            if (curDist > dist[u])
                continue;
            for (int v = 1; v <= size; ++v) {
                if (adjMatrix[u][v]) {
                    int newDist = curDist + adjMatrix[u][v];
                    if (newDist < dist[v]) {
                        dist[v] = newDist;
                        parents[v] = u;
                        pq.push({ newDist, v });
                    }
                }
            }
        }
        for (int u = 1; u <= size; ++u) {
            paths[u].push_back(dist[u]);
            for (int v = u; v != -1; v = parents[v])
                paths[u].push_back(v);
        }
        return paths;
    }

    /* FOR ONLY UNDIRECTED GRAPH */
    int countConnectedComponents()
    {
        vector<bool> visited(size + 1, false);
        int count = 0;
        for (int u = 1; u <= size; ++u) {
            if (!visited[u]) {
                DFS(u, visited, adjMatrix);
                ++count;
            }
        }
        return count;
    }

    bool isConnectedGraph()
    {
        return (countConnectedComponents() == 1);
    }

    vector<int> jointList()
    {
        vector<int> joints;
        int count = countConnectedComponents();
        vector<bool> visited(size + 1, false);
        for (int u = 1; u <= size; ++u) {
            fill(visited.begin(), visited.end(), false);
            visited[u] = true;
            int newCount = 0;
            for (int v = 1; v <= size; ++v) {
                if (!visited[v]) {
                    ++newCount;
                    DFS(v, visited, adjMatrix);
                }
            }
            if (newCount > count)
                joints.push_back(u);
        }
        return joints;
    }

    vector<pair<int, int>> bridgeList()
    {
        vector<pair<int, int>> edges;
        for (int u = 1; u <= size; ++u)
            for (int v = 1; v <= size; ++v)
                if (adjMatrix[u][v] && u < v)
                    edges.push_back({ u, v });
        int count = countConnectedComponents();
        vector<bool> visited(size + 1, false);
        function<void(int u, int s, int t)> dfs = [&](int u, int s, int t) -> void {
            visited[u] = true;
            for (int v = 1; v <= size; ++v) {
                if (adjMatrix[u][v]) {
                    if ((u == s && v == t) || (v == s && u == t))
                        continue;
                    if (!visited[v])
                        dfs(v, s, t);
                }
            }
        };
        vector<pair<int, int>> bridges;
        for (auto& [s, t] : edges) {
            fill(visited.begin(), visited.end(), false);
            int newCount = 0;
            for (int u = 1; u <= size; ++u)
                if (!visited[u]) {
                    ++newCount;
                    dfs(u, s, t);
                }
            if (newCount > count)
                bridges.push_back({ s, t });
        }
        return bridges;
    }

    vector<pair<int, pair<int, int>>> kruskalSpanningTree()
    {
        if (!isConnectedGraph())
            return {};
        vector<int> parents(size + 1);
        for (int u = 1; u <= size; ++u)
            parents[u] = u;
        function<int(int)> findSet = [&](int u) -> int {
            return (u == parents[u]) ? u : parents[u] = findSet(parents[u]);
        };
        function<bool(int, int)> unionSet = [&](int u, int v) -> bool {
            u = findSet(u);
            v = findSet(v);
            if (u != v) {
                parents[v] = u;
                return true;
            }
            return false;
        };
        vector<pair<int, pair<int, int>>> edges;
        for (int u = 1; u <= size; ++u)
            for (int v = 1; v <= size; ++v)
                if (adjMatrix[u][v] && u < v)
                    edges.push_back({ adjMatrix[u][v], { u, v } });
        sort(edges.begin(), edges.end());
        vector<pair<int, pair<int, int>>> MST = { { INF, { 0, 0 } } };
        for (auto& [w, edge] : edges) {
            if (MST.size() == size)
                break;
            auto [u, v] = edge;
            if (unionSet(u, v))
                MST.push_back({ w, { u, v } });
        }
        if (MST.size() < size)
            return { { INF, { 0, 0 } } };
        return MST;
    }

    vector<pair<int, pair<int, int>>> primSpanningTree(int start)
    {
        if (!isConnectedGraph())
            return {};
        vector<pair<int, pair<int, int>>> edges;
        for (int u = 1; u <= size; ++u)
            for (int v = 1; v <= size; ++v)
                if (adjMatrix[u][v] && u < v)
                    edges.push_back({ adjMatrix[u][v], { u, v } });
        vector<bool> inMST(size + 1, false);
        vector<pair<int, pair<int, int>>> MST = { { INF, { 0, 0 } } };
        inMST[start] = true;
        while (MST.size() < size) {
            int minW = INF, U, V;
            for (auto& [w, edge] : edges) {
                auto [u, v] = edge;
                if (((inMST[u] && !inMST[v]) || (!inMST[u] && inMST[v])) && w < minW) {
                    minW = w;
                    U = u, V = v;
                }
            }
            MST.push_back({ minW, { U, V } });
            inMST[U] = inMST[V] = true;
        }
        if (MST.size() < size)
            return { { INF, { 0, 0 } } };
        return MST;
    }

    /* FOR ONLY DIRECTED GRAPH */
    int countWeeklyConnectedComponents()
    {
        vector<vector<int>> newMatrix(size + 1, vector<int>(size + 1, 0));
        for (int u = 1; u <= size; ++u) {
            for (int v = 1; v <= size; ++v) {
                if (adjMatrix[u][v]) {
                    newMatrix[u][v] = 1;
                    newMatrix[v][u] = 1;
                }
            }
        }
        vector<bool> visited(size + 1, false);
        int count = 0;
        for (int u = 1; u <= size; ++u) {
            if (!visited[u]) {
                DFS(u, visited, newMatrix);
                ++count;
            }
        }
        return count;
    }

    bool isWeaklyConnectedGraph()
    {
        return (countWeeklyConnectedComponents() == 1);
    }

    stack<int> topologicalSort()
    {
        vector<bool> visited(size + 1, false);
        stack<int> st;
        function<void(int)> dfs = [&](int u) -> void {
            visited[u] = true;
            for (int v = 1; v <= size; ++v) {
                if (adjMatrix[u][v] && !visited[v])
                    dfs(v);
            }
            st.push(u);
        };
        for (int u = 1; u <= size; ++u) {
            if (!visited[u])
                dfs(u);
        }
        return st;
    }

    int countStronglyConnectedComponents()
    {
        vector<vector<int>> revMatrix(size + 1, vector<int>(size + 1, 0));
        for (int u = 1; u <= size; ++u)
            for (int v = 1; v <= size; ++v)
                revMatrix[v][u] = adjMatrix[u][v];
        vector<bool> visited(size + 1, false);
        stack<int> st = topologicalSort();
        int count = 0;
        while (!st.empty()) {
            int v = st.top();
            st.pop();
            if (!visited[v]) {
                DFS(v, visited, revMatrix);
                ++count;
            }
        }
        return count;
    }

    bool isStronglyConnectedGraph()
    {
        return (countStronglyConnectedComponents() == 1);
    }

    void bellmanFordPath()
    {
    }

    vector<vector<vector<int>>> floydPath()
    {
        vector<vector<int>> dist(size + 1, vector<int>(size + 1, INF));
        vector<vector<int>> next(size + 1, vector<int>(size + 1, -1));

        for (int u = 1; u <= size; ++u) {
            for (int v = 1; v <= size; ++v) {
                if (adjMatrix[u][v]) {
                    dist[u][v] = adjMatrix[u][v];
                    next[u][v] = v;
                }
            }
            dist[u][u] = 0;
            next[u][u] = u;
        }
        for (int k = 1; k <= size; ++k) {
            for (int u = 1; u <= size; ++u) {
                for (int v = 1; v <= size; ++v) {
                    if (dist[u][v] > dist[u][k] + dist[k][v]) {
                        dist[u][v] = dist[u][k] + dist[k][v];
                        next[u][v] = next[u][k];
                    }
                }
            }
        }
        vector<vector<vector<int>>> paths(size + 1, vector<vector<int>>(size + 1));
        for (int u = 1; u <= size; ++u) {
            for (int v = 1; v <= size; ++v) {
                if (dist[u][v] == INF || next[u][v] == -1)
                    continue;

                paths[u][v].push_back(dist[u][v]);
                for (int x = u; x != v; x = next[x][v])
                    paths[u][v].push_back(x);
                paths[u][v].push_back(v);
            }
        }
        return paths;
    }
};
inline void prepare()
{
    // prepare in here
    return;
}
inline void hhtuann()
{
    int n;
    cin >> n;
    vector<vector<int>> matrix(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> matrix[i][j];

    Graph g(matrix);
    vector<vector<vector<int>>> paths = g.floydPath();
    for (int u = 1; u <= n; ++u) {
        for (int v = 1; v <= n; ++v) {
            if (paths[u][v][0] == INF) {
                cout << "K/c " << u << " -> " << v << " = INF;" << endl;
                continue;
            }
            cout << "K/c " << u << " -> " << v << " = " << paths[u][v][0] << "; ";
            cout << paths[u][v][1];
            for (int i = 2; i < paths[u][v].size(); ++i)
                cout << " --> " << paths[u][v][i];
            cout << endl;
        }
        cout << endl;
    }

    return;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    if (USING_FILE) {
        freopen((NAME + ".inp").c_str(), "r", stdin);
        freopen((NAME + ".out").c_str(), "r", stdout);
    }

    prepare();
    int testcase = 1;

    if (USING_TESTCASE) {
        cin >> testcase;
        cin.ignore();
    }

    for (int tc = 1; tc <= testcase; ++tc) {
        cerr << "===== Running on test: " << tc << " =====" << endl;
        hhtuann(); // solve function
        cerr << "==============================" << endl
             << endl;
    }

    return 0;
}
/* Take Off Toward Your Dream ! */