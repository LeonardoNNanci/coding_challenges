#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const* argv[]) {
  int C;
  cin >> C;
  cin.ignore();
  while (C--) {
    string text;
    getline(cin, text);

    bool afterSpace = true;
    for (char ch : text) {
      if (ch == ' ')
        afterSpace = true;
      else if (afterSpace) {
        cout << ch;
        afterSpace = false;
      }
    }

    cout << endl;
  }
  return 0;
}