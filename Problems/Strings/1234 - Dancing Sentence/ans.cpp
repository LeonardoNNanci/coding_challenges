#include <bits/stdc++.h>

using namespace std;

int main() {
  string text;
  while (getline(cin, text)) {
    bool toUpper = 1;
    for (int i = 0; i < text.length(); i++) {
      text[i] = toUpper ? toupper(text[i]) : tolower(text[i]);
      if (text[i] != ' ')
        toUpper ^= 1;
    }

    cout << text << endl;
  }
  return 0;
}
