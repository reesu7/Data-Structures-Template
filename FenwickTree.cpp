class FenwickTree {
    vector<int> bit;
    int n;
public:
    FenwickTree(int size) : n(size) {
        bit.assign(n + 1, 0);
    }
    FenwickTree(const vector<int>& values) : n(values.size() - 1) {
        bit.assign(n + 1, 0);
        for (int i = 1; i <= n; ++i)
            update(i, values[i]);
    }
    void update(int index, int delta) {
        for (; index <= n; index += index & -index)
            bit[index] += delta;
    }

    int query(int index) {
        int sum = 0;
        for (; index > 0; index -= index & -index)
            sum += bit[index];
        return sum;
    }

    int rangeQuery(int left, int right) {
        return query(right) - query(left - 1);
    }
};
