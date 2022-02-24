#include <bits/stdc++.h>

using namespace std;

int main() {
  map<string, int> freqs;

  int n, c = 0;
  float count;
  string tree;
  cout << fixed;

  cin >> n;
  getline(cin, tree);
  getline(cin, tree);
  while (!cin.eof()) {
    count = 0;
    while (getline(cin, tree) && !tree.empty()) {
      freqs[tree] += 1;
      count++;
    }

    if (c++ != 0)
      cout << endl;
    for (auto a : freqs) {
      cout << a.first << ' ' << setprecision(4) << a.second / count * 100
           << '\n';
    }

    freqs.clear();
  }

  return 0;
}