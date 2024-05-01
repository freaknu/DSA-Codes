class Modular {
private:
    int ModulerInverse(int a, int m) {
        int m0 = m;
        int y = 0, x = 1;

        if (m == 1) return 0;

        while (a > 1) {
            int q = a / m;
            int t = m;
            m = a % m, a = t;
            t = y;
            y = x - q * y;
            x = t;
        }
        if (x < 0) x += m0;

        return x;
    }
public:
    int Addition(int a, int b, int m) {
        return ((a % m) + (b % m)) % m;
    }
    int Substraction(int a, int b, int m) {
        return ((a % m) - (b % m)) % m;
    }
    int MultiPlication(int a, int b, int m) {
        return ((a % m) * (b % m)) % m;
    }
    int Division(int a, int b, int m) {
        int inv = ModulerInverse(b, m);
        if (inv == -1)return -1;
        return (a * inv) % m;
    }
    int Exponentiation(int x, int n, int m) {
        if (n == 0) return 1 % m;
        long long res = Exponentiation(x, n / 2, m);
        u = (u * u) % m;
        if (n % 2 == 1) {
            u = (u * x) % m;
            return u;
        }
    }
};
