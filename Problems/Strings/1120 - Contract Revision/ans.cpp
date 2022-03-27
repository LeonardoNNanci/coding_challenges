#include <bits/stdc++.h>

using namespace std;

int main() {
  while (true) {
    char d;
    string text;
    cin >> d >> text;
    if (d == '0')
      break;
    text.erase(remove(text.begin(), text.end(), d), text.end());
    bool zeroLeft = 1;
    for (auto ch : text)
      if (!zeroLeft || ch != '0') {
        cout << ch;
        zeroLeft = 0;
      }
    if (zeroLeft)
      cout << 0;
    cout << endl;
  }
}