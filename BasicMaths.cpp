class BasicOperationMath {
public:
    int Power(int x, int y, int p) {
        int res = 1;
        x = x % p;
        while ( y > 0 ) {
            if ( y & 1 ) {
                res = (res * x) % p;
            }
            y = y >> 1;
            x = (x * x) % p;
        }
        return res;
    }
    int gcd(int a, int b, int& x, int& y) {
        if (b == 0) {
            x = 1;
            y = 0;
            return a;
        }
        int x1, y1;
        int d = gcd(b, a % b, x1, y1);
        x = y1;
        y = x1 - y1 * (a / b);
        return d;
    }

    int extendedEuclidean(int a, int m, int& x, int& y) {
        int g = gcd(a, m, x, y);
        if (g != 1) {
            return -1;
        }
        return (x % m + m) % m;
    }

    int modularInverseEuclideanDivision(int a, int m) {
        return a <= 1 ? a : m - (long long)(m / a) * modularInverseEuclideanDivision(m % a, m) % m;
    }
    vector<int> computeInverse(int m) {
        vector<int> inverse(m);
        inverse[1] = 1;
        for (int a = 2; a < m; a++) {
            inverse[a] = m - (long long)(m / a) * inverse[m % a] % m;
        }
        return inverse;
    }

    vector<int> inverseMod(vector<int>& array, int m) {
        int n = array.size();
        if (n == 0) return {};

        vector<int> ansInverse(n);
        int v = 1;
        for (int i = 0; i < n; i++) {
            ansInverse[i] = v;
            v = (v * (long long)array[i]) % m;
        }

        int x, y;
        gcd(v, m, x, y);
        x = (x % m + m) % m;

        vector<int> b(n);
        for (int i = n - 1; i >= 0; i--) {
            b[i] = (x * (long long)ansInverse[i]) % m;
            x = (x * (long long)array[i]) % m;
        }
        return b;
    }
};
