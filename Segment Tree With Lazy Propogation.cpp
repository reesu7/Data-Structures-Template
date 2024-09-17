class SGTREE {
    vector<int> sgtree, lazytree, a;
public:
    SGTREE(int n, vector<int>& ap) {
        sgtree.resize(4 * n, 0);
        lazytree.resize(4 * n, 0);
        a = ap;
    }

    void build(int idx, int low, int high) {
        if (low == high) {
            sgtree[idx] = a[low];
            return;
        }
        int mid = (low + high) / 2;
        build(2 * idx + 1, low, mid);
        build(2 * idx + 2, mid + 1, high);
        sgtree[idx] = sgtree[2 * idx + 1] + sgtree[2 * idx + 2];
    }

    void propagate(int idx, int low, int high) {
        if (lazytree[idx] != 0) {
            sgtree[idx] += (high - low + 1) * lazytree[idx];
            if (low != high) {
                lazytree[2 * idx + 1] += lazytree[idx];
                lazytree[2 * idx + 2] += lazytree[idx];
            }
            lazytree[idx] = 0;
        }
    }

    int query(int idx, int low, int high, int l, int r) {
        propagate(idx, low, high);
        if (r < low || l > high) return 0;
        if (low >= l && high <= r) return sgtree[idx];
        int mid = (low + high) / 2;
        int left = query(2 * idx + 1, low, mid, l, r);
        int right = query(2 * idx + 2, mid + 1, high, l, r);
        return left + right;
    }
    void update(int idx, int low, int high, int l, int r, int val) {
        propagate(idx, low, high);
        if (r < low || l > high) return;
        if (low >= l && high <= r) {
            sgtree[idx] += (high - low + 1) * val;
            if (low != high) {
                lazytree[2 * idx + 1] += val;
                lazytree[2 * idx + 2] += val;
            }
            return;
        }
        int mid = (low + high) / 2;
        update(2 * idx + 1, low, mid, l, r, val);
        update(2 * idx + 2, mid + 1, high, l, r, val);
        sgtree[idx] = sgtree[2 * idx + 1] + sgtree[2 * idx + 2];
    }
};
