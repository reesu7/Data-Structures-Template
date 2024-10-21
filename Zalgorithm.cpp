class Zalgorithm {
    vector<int> z;
    string text, pattern;

public:
    Zalgorithm(string t, string p, vector<int>& zf) {
        text = t;
        pattern = p;
        string combined = pattern + "$" + text;
        constructZarray(combined, z);
        for (int i = 0; i < z.size(); i++) {
            zf[i] = z[i];
        }
    }

private:
    void constructZarray(string s, vector<int>& z) {
        int n = s.size();
        z.resize(n);
        z[0] = n;
        int l = 0, r = 0;
        for (int i = 1; i < n; i++) {
            if (i > r) {
                l = r = i;
                while (r < n && s[r] == s[r - l]) r++;
                z[i] = r - l;
                r--;
            } else {
                int k = i - l;
                if (z[k] < r - i + 1) z[i] = z[k];
                else {
                    l = i;
                    while (r < n && s[r] == s[r - l]) r++;
                    z[i] = r - l;
                    r--;
                }
            }
        }
    }
};
