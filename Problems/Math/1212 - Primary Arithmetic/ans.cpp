#include <bits/stdc++.h>

using namespace std;

int main() {
  string X, Y;
  while (true) {
    cin >> X >> Y;
    if (X == "0" && Y == "0")
      break;

    int count = 0, carry = 0, x, y;
    int maX_l = max(X.length(), Y.length());
    for (int i = 1; i <= maX_l; i++) {
      x = (int)X.length() - i < 0 ? 0 : X[X.length() - i] - '0';
      y = (int)Y.length() - i < 0 ? 0 : Y[Y.length() - i] - '0';
      if (x + y + carry >= 10) {
        carry = 1;
        count++;
      } else
        carry = 0;
    }

    if (count == 0)
      cout << "No carry operation." << endl;
    else if (count == 1)
      cout << "1 carry operation." << endl;
    else
      cout << count << " carry operations." << endl;
  }

  return 0;
}