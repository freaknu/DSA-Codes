class PrefixSum {
public:
    vector<int>Psum_1D() {
        int n;
        cin >> n;
        vector<int>vec(n), prefSum(n);
        for (int i = 1; i < n; i++) cin >> vec[i];
        prefSum[0] = [0];
        for (int i = 1; i < n; i++) psum[i] = psum[i - 1] + vec[i];
        return prefSum;
    }
    static const int MAXN = 1005;
    int a[MAXN][MAXN];
    int psum[MAXN][MAXN];

    void getPrefixSum() {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }
        psum[0][0] = a[0][0];
        for (int j = 1; j < m; j++) {
            psum[0][j] = psum[0][j - 1] + a[0][j];
        }
        for (int i = 1; i < n; i++) {
            psum[i][0] = psum[i - 1][0] + a[i][0];
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                psum[i][j] = psum[i - 1][j] + psum[i][j - 1] - psum[i - 1][j - 1] + a[i][j];
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << psum[i][j] << " ";
            }
            cout << endl;
        }
    }
};
