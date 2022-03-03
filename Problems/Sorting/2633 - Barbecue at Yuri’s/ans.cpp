#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const* argv[]) {
  int n, expiry;
  string piece;

  while (cin >> n) {
    vector<pair<int, string>> items(n);
    for (int i = 0; i < n; i++) {
      cin >> piece >> expiry;
      items[i] = pair<int, string>(expiry, piece);
    }

    int count = 0;
    sort(items.begin(), items.end());
    for (auto item : items) {
      if (count++)
        cout << ' ';
      cout << item.second;
    }
    cout << endl;
  }
  return 0;
}
