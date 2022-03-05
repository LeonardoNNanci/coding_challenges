#include <bits/stdc++.h>

using namespace std;

// access is done in 0 indexing
// calculations are done in 1 indexing
template <class T>
class SegmentTree {
 private:
  int n;
  T neutral;
  vector<T> t;

  T operation(T l, T r) { return l * r; }

  void build() {
    for (int i = n - 1; i > 0; --i)
      t[i] = operation(t[i << 1], t[i << 1 | 1]);
  }

 public:
  SegmentTree(int n, T neutral) {
    this->n = n;
    this->neutral = neutral;
    t.assign(n * 2, neutral);
  }

  SegmentTree(vector<T> arr, T neutral) {
    this->n = arr.size();
    this->neutral = neutral;
    t.assign(n * 2, neutral);
    for (int i = 0; i < n; i++) {
      t[n + i] = arr[i];
    }
    build();
  }

  // set value at position p
  void modify(int i, T value) {
    for (t[i += n] = value; i >>= 1;)
      t[i] = operation(t[i << 1], t[i << 1 | 1]);
  }

  // sum on interval [l, r)
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

int get_signal(int x) {
  if (x > 0)
    return 1;
  if (x < 0)
    return -1;
  return 0;
}

int main(int argc, char const* argv[]) {
  int n, k, x, i;
  int j;
  char command;
  while (cin >> n >> k) {
    SegmentTree<int> st(n, 1);
    for (i = 0; i < n; i++) {
      cin >> x;
      st.modify(i, get_signal(x));
    }

    while (k--) {
      cin >> command >> i >> j;

      if (command == 'C') {
        st.modify(i - 1, get_signal(j));
      }

      else {
        int ans = st.query(i - 1, j);
        char signal = '0';
        if (ans > 0)
          signal = '+';
        else if (ans < 0)
          signal = '-';
        cout << signal;
      }
    }
    cout << endl;
  }
  return 0;
}
