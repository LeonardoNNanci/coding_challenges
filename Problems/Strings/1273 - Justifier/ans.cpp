#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const* argv[]) {
  int count = 0;
  while (true) {
    int n, max_len = 0;
    cin >> n;

    if (!n)
      break;

    if (count++)
      cout << endl;

    vector<string> texts(n);
    for (int i = 0; i < n; i++) {
      cin >> texts[i];
      max_len = max({max_len, (int)texts[i].length()});
    }

    for (auto text : texts)
      cout << right << setw(max_len) << text << endl;
  }
  return 0;
}