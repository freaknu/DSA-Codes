class Graph {
public:
    unordered_map<int, list<int>> adjacent;

    void addElement(int u, int v, bool direction) {
        adjacent[u].push_back(v);
        if (!direction) {
            adjacent[v].push_back(u);
        }
    }

    void dfs(int node, unordered_map<int, bool> &visit, stack<int> &s) {
        visit[node] = true;
        for (auto j : adjacent[node]) {
            if (!visit[j]) {
                dfs(j, visit, s);
            }
        }
        s.push(node);
    }

    void bfs(int node, vector<bool>& visited) {
        visited[node] = true;
        queue<int> q;
        q.push(node);
        while (!q.empty()) {
            int front = q.front();
            cout << front << " ";
            q.pop();
            for (auto neighbour : adjacent[front]) {
                if (!visited[neighbour]) {
                    visited[neighbour] = true;
                    q.push(neighbour);
                }
            }
        }
    }

    vector<int> dijkstra(int vertices, vector<vector<int>>& edges, int source) {
        set<pair<int, int>> set;
        unordered_map<int, list<pair<int, int>>> adj;
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back(make_pair(v, w));
            adj[v].push_back(make_pair(u, w));
        }

        vector<int> distance(vertices, INT_MAX);
        distance[source] = 0;
        set.insert(make_pair(0, source));

        while (!set.empty()) {
            auto top = *(set.begin());
            int nodeDis = top.first;
            int topnode = top.second;
            set.erase(set.begin());
            for (auto j : adj[topnode]) {
                if (nodeDis + j.second < distance[j.first]) {
                    auto record = set.find(make_pair(distance[j.first], j.first));
                    if (record != set.end()) {
                        set.erase(record);
                    }
                    distance[j.first] = nodeDis + j.second;
                    set.insert(make_pair(distance[j.first], j.first));
                }
            }
        }
        return distance;
    }

    vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, vector<pair<pair<int, int>, int>>& g) {
        unordered_map<int, list<pair<int, int>>> adj;

        for (auto &edge : g) {
            int u = edge.first.first;
            int v = edge.first.second;
            int w = edge.second;
            adj[u].push_back(make_pair(v, w));
            adj[v].push_back(make_pair(u, w));
        }

        vector<int> key(n + 1, INT_MAX);
        vector<int> parent(n + 1, -1);
        vector<bool> mst(n + 1, false);
        key[1] = 0;
        parent[1] = -1;
        for (int i = 0; i < n; i++) {
            int mini = INT_MAX;
            int u;
            for (int v = 1; v <= n; v++) {
                if (!mst[v] && key[v] < mini) {
                    u = v;
                    mini = key[v];
                }
            }
            mst[u] = true;
            for (auto &i : adj[u]) {
                int v = i.first;
                int w = i.second;
                if (!mst[v] && w < key[v]) {
                    parent[v] = u;
                    key[v] = w;
                }
            }
        }
        vector<pair<pair<int, int>, int>> ans;
        for (int i = 2; i <= n; i++) {
            ans.push_back({{parent[i], i}, key[i]});
        }
        return ans;
    }

    vector<int> topologicalSort(int v, vector<vector<int>> &edges) {
        unordered_map<int, list<int>> adj;
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }
        vector<int> indegree(v);
        for (auto &i : adj) {
            for (auto &j : i.second) {
                indegree[j]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < v; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        vector<int> ans;
        while (!q.empty()) {
            int front = q.front();
            q.pop();
            ans.push_back(front);
            for (auto &i : adj[front]) {
                indegree[i]--;
                if (indegree[i] == 0) {
                    q.push(i);
                }
            }
        }
        return ans;
    }

    vector<int> shortestPath(vector<pair<int, int>> edges, int n, int m, int s, int t) {
        unordered_map<int, list<int>> adj;
        for (auto &edge : edges) {
            int u = edge.first;
            int v = edge.second;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        unordered_map<int, bool> visit;
        unordered_map<int, int> parent;
        vector<int> ans;
        queue<int> q;
        q.push(s);
        visit[s] = true;
        parent[s] = -1;
        while (!q.empty()) {
            int front = q.front();
            q.pop();
            for (auto &i : adj[front]) {
                if (!visit[i]) {
                    visit[i] = true;
                    parent[i] = front;
                    q.push(i);
                }
            }
        }
        int curr = t;
        ans.push_back(t);
        while (curr != s) {
            curr = parent[curr];
            ans.push_back(curr);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    bool isCycle(int node, unordered_map<int, bool> &dfs, unordered_map<int, bool> &visit, unordered_map<int, list<int>> &adj) {
        visit[node] = true;
        dfs[node] = true;
        for (auto &neighbour : adj[node]) {
            if (!visit[neighbour]) {
                bool cycleDetect = isCycle(neighbour, dfs, visit, adj);
                if (cycleDetect) {
                    return true;
                }
            }
            else if (dfs[neighbour]) {
                return true;
            }
        }
        dfs[node] = false;
        return false;
    }

    int stronglyConnectedComponents(int v, vector<vector<int>> &edges) {
        unordered_map<int, list<int>> adjlist;
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adjlist[u].push_back(v);
        }
        stack<int> st;
        unordered_map<int, bool> visit;
        for (int i = 0; i < v; i++) {
            if (!visit[i]) {
                dfs(i, visit, adjlist, st);
            }
        }
        unordered_map<int, list<int>> graph;
        for (int i = 0; i < v; i++) {
            visit[i] = false;
            for (auto &nbr : adjlist[i]) {
                graph[nbr].push_back(i);
            }
        }
        int cnt = 0;
        while (!st.empty()) {
            int top = st.top();
            st.pop();
            if (!visit[top]) {
                cnt++;
                dfs(top, visit, graph, st);
            }
        }
        return cnt;
    }

    void solve(int node, unordered_map<int, bool> &visit, unordered_map<int, list<int>> &adjlist, stack<int> &st) {
        visit[node] = true;
        for (auto &nbr : adjlist[node]) {
            if (!visit[nbr]) {
                solve(nbr, visit, adjlist, st);
            }
        }
        st.push(node);
    }
};
