class SgTree {
    vector<int> tree, a;

public:
    SgTree(int n, vector<int>& dp) {
        tree.resize(4 * n);
        a.resize(n);
        for (int i = 0; i < n; i++) {
            a[i] = dp[i];
        }
        build(0, 0, n - 1);
    }

    void build(int idx, int low, int high) {
        if (low == high) {
            tree[idx] = a[low];
            return;
        }
        int mid = (low + high) / 2;
        build(2 * idx + 1, low, mid);
        build(2 * idx + 2, mid + 1, high);
        tree[idx] = lcm(tree[2 * idx + 1], tree[2 * idx + 2]);
    }

    int query(int idx, int low, int high, int l, int r) {
        if (l <= low && r >= high) {
            return tree[idx];
        }
        if (high < l || low > r) {
            return 1;
        }
        int mid = (low + high) / 2;
        int lft = query(2 * idx + 1, low, mid, l, r);
        int rgt = query(2 * idx + 2, mid + 1, high, l, r);
        return lcm(lft, rgt);
    }

    void update(int pos, int val, int low, int high, int idx) {
        if (low == high) {
            tree[idx] = val;
            a[pos] = val;
            return;
        }
        int mid = (low + high) / 2;
        if (pos > mid) {
            update(pos, val, mid + 1, high, 2 * idx + 2);
        } else {
            update(pos, val, low, mid, 2 * idx + 1);
        }
        tree[idx] = lcm(tree[2 * idx + 1], tree[2 * idx + 2]);
    }
};
