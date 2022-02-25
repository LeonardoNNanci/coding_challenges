#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, q;
  scanf("%d", &n);
  while (n--) {
    string s, r;
    cin >> s;
    cin >> q;
    while (q--) {
      cin >> r;

      int j = 0;
      for (char c : s)
        if (r[j] == c)
          j++;

      if (j == r.size())
        cout << "Yes" << endl;
      else
        cout << "No" << endl;
    }
  }

  return 0;
}