#include <bits/stdc++.h>

using namespace std;

int main() {
  string one = "one";
  int c;
  cin >> c;
  while (c--) {
    string str;
    cin >> str;
    if (str.length() == 5)
      cout << 3 << endl;

    else {
      int count = 0;
      for (int i = 0; i < 3; i++)
        if (str[i] != one[i])
          count++;

      count <= 1 ? cout << 1 : cout << 2;
      cout << endl;
    }
  }
  return 0;
}