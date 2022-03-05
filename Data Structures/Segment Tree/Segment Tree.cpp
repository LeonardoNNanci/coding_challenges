// access is done in 0 indexing
// calculations are done in 1 indexing
template <class T>
class SegmentTree {
 private:
  int n;
  T neutral;
  vector<T> t;

  // the main operation of the tree
  T operation(T l, T r) { return l * r; }

  void build() {
    for (int i = n - 1; i > 0; --i)
      t[i] = operation(t[i << 1], t[i << 1 | 1]);
  }

 public:
  // Initialize empty
  SegmentTree(int n, T neutral) {
    this->n = n;
    this->neutral = neutral;
    t.assign(n * 2, neutral);
  }

  // Initialize from array
  SegmentTree(vector<T> arr, T neutral) {
    this->n = arr.size();
    this->neutral = neutral;
    t.assign(n * 2, neutral);
    for (int i = 0; i < n; i++) {
      t[n + i] = arr[i];
    }
    build();
  }

  // set value at position i
  void modify(int i, T value) {
    for (t[i += n] = value; i >>= 1;)
      t[i] = operation(t[i << 1], t[i << 1 | 1]);
  }

  // query on interval [l, r)
  T query(int l, int r) {
    T resl = neutral, resr = neutral;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1)
        resl = operation(resl, t[l++]);
      if (r & 1)
        resr = operation(t[--r], resr);
    }
    return operation(resl, resr);
  }

  void clear() {
    t.clear();
    n = 0;
  }
};