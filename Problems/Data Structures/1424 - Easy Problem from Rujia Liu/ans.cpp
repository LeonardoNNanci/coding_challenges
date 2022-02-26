#include <bits/stdc++.h>

using namespace std;

int main() {
  map<int, vector<int>> hash;
  int n, m, temp, k, v;
  while (cin >> n >> m) {
    for (int i = 1; i <= n; i++) {
      cin >> temp;
      if (hash.find(temp) != hash.end())
        hash[temp].push_back(i);
      else
        hash[temp] = {i};
    }
    while (m--) {
      cin >> k >> v;
      auto positions = hash[v];
      if (k <= positions.size())
        cout << positions[k - 1] << endl;
      else
        cout << 0 << endl;
    }

    hash.clear();
  }

  return 0;
}