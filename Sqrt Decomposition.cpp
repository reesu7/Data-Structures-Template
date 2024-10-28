class SQRT {
    vector<int> sum;
    vector<int> a;
    int sqrtn;

public:
    SQRT(int n, vector<int>& arr) {
        a = arr;
        sqrtn = sqrt(n);
        sum.resize((n + sqrtn - 1) / sqrtn, 0);
        for (int i = 0; i < n; i++) {
            sum[i / sqrtn] += a[i];
        }
    }

    int query(int l, int r) {
        int leftBlock = l / sqrtn, rightBlock = r / sqrtn;
        int result = 0;

        if (leftBlock == rightBlock) {
            for (int i = l; i <= r; i++) result += a[i];
        } else {
            for (int i = l; i < (leftBlock + 1) * sqrtn; i++) result += a[i];
            for (int i = leftBlock + 1; i < rightBlock; i++) result += sum[i];
            for (int i = rightBlock * sqrtn; i <= r; i++) result += a[i];
        }
        
        return result;
    }

    void update(int idx, int val) {
        int block = idx / sqrtn;
        sum[block] += val - a[idx];
        a[idx] = val;
    }
};
