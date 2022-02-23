#include <bits/stdc++.h>

using namespace std;

int main() {
  int c;
  vector<int> hash[105];

  cin >> c;
  while (c--) {
    int n, x, temp;
    cin >> n >> x;
    for (int i = 0; i < x; i++) {
      cin >> temp;
      hash[temp % n].push_back(temp);
    }

    for (int i = 0; i < n; i++) {
      cout << i << " -> ";
      for (int data : hash[i]) {
        cout << data << " -> ";
      }
      cout << '\\' << endl;
    }
    if (c > 0) {
      cout << endl;
      for (int i = 0; i < n; i++)
        hash[i].clear();
    }
  }

  return 0;
}