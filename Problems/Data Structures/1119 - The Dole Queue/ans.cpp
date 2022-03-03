#include <bits/stdc++.h>

using namespace std;

list<int> circle;

list<int>::iterator circular_next(list<int>::iterator it) {
  list<int>::iterator n = next(it);
  if (n == circle.end()) {
    return circle.begin();
  }
  return n;
}

list<int>::iterator circular_prev(list<int>::iterator it) {
  list<int>::iterator n = prev(it);
  if (n == circle.end()) {
    return --circle.end();
  }
  return n;
}

int main(int argc, char const* argv[]) {
  int k, n, m;

  while (true) {
    cin >> n >> k >> m;
    if (!(n || k || m))
      break;

    for (int i = 1; i <= n; i++)
      circle.push_back(i);

    list<int>::iterator cw = --circle.begin(), cc = circle.end();
    while (!circle.empty()) {
      for (int i = 0; i < k; i++) {
        cw = circular_next(cw);
      }
      for (int i = 0; i < m; i++) {
        cc = circular_prev(cc);
      }

      auto prev_cw = circular_prev(cw), next_cc = circular_next(cc);
      if (cw == next_cc)
        next_cc = circular_next(next_cc);
      if (cc == prev_cw)
        prev_cw = circular_prev(prev_cw);

      cout << setfill(' ') << setw(3) << *cw;
      circle.erase(cw);
      if (cw != cc) {
        cout << setfill(' ') << setw(3) << *cc;
        circle.erase(cc);
      }

      cw = prev_cw;
      cc = next_cc;

      if (circle.empty())
        break;
      cout << ',';
    }
    cout << endl;
  }
  return 0;
}
