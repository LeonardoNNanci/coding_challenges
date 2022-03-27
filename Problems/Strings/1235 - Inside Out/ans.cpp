#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const* argv[]) {
  int C;
  cin >> C;
  cin.ignore();
  while (C--) {
    string text;
    getline(cin, text);
    for (int i = text.length() / 2 - 1; i >= 0; i--)
      cout << text[i];
    for (int i = text.length() - 1; i > text.length() / 2 - 1; i--)
      cout << text[i];
    cout << endl;
  }
  return 0;
}