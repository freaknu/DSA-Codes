class DisjointSet {
    vector<int> rank, parent, size;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findparent(int node) {
        if (node == parent[node]) return node;
        return parent[node] = findparent(parent[node]);
    }

    void UnionByRank(int u, int v) {
        int UltParent_U = findparent(u);
        int UltParent_V = findparent(v);
        if (UltParent_U == UltParent_V) return;
        if (rank[UltParent_U] < rank[UltParent_V]) {
            parent[UltParent_U] = UltParent_V;
        } else if (rank[UltParent_V] < rank[UltParent_U]) {
            parent[UltParent_V] = UltParent_U;
        } else {
            parent[UltParent_U] = UltParent_V;
            rank[UltParent_V]++;
        }
    }

    void UnionBySize(int u, int v) {
        int Ualp_u = findparent(u);
        int Ualp_v = findparent(v);
        if (Ualp_u == Ualp_v) return;
        if (size[Ualp_u] < size[Ualp_v]) {
            parent[Ualp_u] = Ualp_v;
            size[Ualp_v] += size[Ualp_u];
        } else {
            parent[Ualp_v] = Ualp_u;
            size[Ualp_u] += size[Ualp_v];
        }
    }
};
