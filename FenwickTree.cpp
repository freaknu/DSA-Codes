#include <bits/stdc++.h>
using namespace std;
class FenwickTree {
public:
    int N;
    int *Fenwick;

    void update(int i, int value) {
        while (i < N) {
            Fenwick[i] += value;
            i += (i & (-i));
        }
    }

    int sum(int i) {
        int sum = 0;
        while (i > 0) {
            sum += Fenwick[i];
            i = i - (i & (-i));
        }
        return sum;
    }

    int rangeSum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
};
