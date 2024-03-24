class SegmentTree {
public:
  int arr[10005], seg[4 * 10005];
  int lazy[4 * 10005];

  void build(int index, int low, int high) {
    if (low == high) {
      seg[index] = arr[low];
      return;
    }
    int mid = (low + high) >> 1;
    build(2 * index + 1, low, mid);
    build(2 * index + 2, mid + 1, high);
    seg[index] = min(seg[2 * index + 1], seg[2 * index + 2]);
  }
  void update(int index, int low, int high, int pos, int val) {
    if (pos < low || pos > high)
      return;
    if (low == high) {
      seg[index] = val;
      return;
    }
    int mid = (low + high) >> 1;
    update(2 * index + 1, low, mid, pos, val);
    update(2 * index + 2, mid + 1, high, pos, val);
    seg[index] = min(seg[2 * index + 1], seg[2 * index + 2]);
  }
  void updateRange(int index, int low, int high, int left, int right,
                   int value) {
    if (lazy[index] != 0) {
      seg[index] += lazy[index];
      if (low != high) {
        lazy[2 * index + 1] += lazy[index];
        lazy[2 * index + 2] += lazy[index];
      }
      lazy[index] = 0;
    }
    if (high < left || right < low) {
      return;
    }
    if (left <= low && high <= right) {
      seg[index] += (high - low + 1) * value;
      if (low != high) {
        lazy[2 * index + 1] += value;
        lazy[2 * index + 2] += value;
      }
      return;
    }
    int mid = (low + high) >> 1;
    updateRange(2 * index + 1, low, mid, left, right, value);
    updateRange(2 * index + 2, mid + 1, high, left, right, value);
    seg[index] = min(seg[2 * index + 1], seg[2 * index + 2]);
  }

  int query(int index, int low, int high, int left, int right) {
    if (right < low || high < left)
      return INT_MAX;
    if (left <= low && high <= right)
      return seg[index];
    int mid = (low + high) >> 1;
    int leftVal = query(2 * index + 1, low, mid, left, right);
    int rightVal = query(2 * index + 2, mid + 1, high, left, right);
    return min(leftVal, rightVal);
  }
  void lazyPropagation(int index, int low, int high, int left, int right,
                       int value) {
    if (lazy[index] != 0) {
      seg[index] += (high - low + 1) * lazy[index];
      if (low != high) {
        lazy[2 * index + 1] += lazy[index];
        lazy[2 * index + 2] += lazy[index];
      }
      lazy[index] = 0;
    }
    if (low > right || high < left) {
      return;
    }
    if (left <= low && right >= high) {
      seg[index] += (high - low + 1) * value;
      if (low != high) {
        lazy[2 * index + 1] += value;
        lazy[2 * index + 2] += value;
      }
      return;
    }
    int mid = (low + high) >> 1;
    lazyPropagation(2 * index + 1, low, mid, left, right, value);
    lazyPropagation(2 * index + 2, mid + 1, high, left, right, value);
    seg[index] = seg[2 * index + 1] + seg[2 * index + 2];
  }
};
