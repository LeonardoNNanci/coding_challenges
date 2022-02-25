#include <bits/stdc++.h>

using namespace std;

int main() {
  int m, n;
  int cost, total;
  string word;
  map<string, long long> dict;

  cin >> m >> n;
  while (m--) {
    cin >> word;
    cin >> cost;
    dict[word] = cost;
  }

  while (n--) {
    total = 0;
    cin >> word;
    do {
      total += dict[word];
      cin >> word;
    } while (word != ".");
    cout << total << endl;
  }

  return 0;
}