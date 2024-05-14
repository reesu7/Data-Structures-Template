class DSU {
    vector<int> rank, parent, size;
public:
    DSU(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++) 
            parent[i] = i;
    }

    int findUpar(int node) {
        if (node == parent[node]) 
            return node;
        return parent[node] = findUpar(parent[node]);
    }

    void unionByrank(int u, int v) {
        int ulp = findUpar(u);
        int vlp = findUpar(v);
        if (ulp == vlp) 
            return;
        if (rank[ulp] < rank[vlp]) 
            parent[ulp] = vlp;
        else if (rank[ulp] > rank[vlp]) 
            parent[vlp] = ulp;
        else {
            parent[vlp] = ulp;
            rank[ulp]++;
        }
    }

    void unionBysize(int u, int v) {
        int ulp = findUpar(u);
        int vlp = findUpar(v);
        if (ulp == vlp) 
            return;
        if (size[ulp] < size[vlp]) 
            swap(ulp, vlp);
        parent[vlp] = ulp;
        size[ulp] += size[vlp];
    }
};
