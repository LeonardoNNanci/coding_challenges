#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const* argv[]) {
  int c, n;
  string text;
  cin >> c;
  while (c--) {
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; i++) {
      cin >> text;
      for (int j = 0; j < text.length(); j++)
        sum += (text[j] - 'A') + i + j;
    }
    cout << sum << endl;
  }
  return 0;
}