#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const* argv[]) {
  string input;
  list<char> msg;
  list<char>::iterator p;

  while (cin >> input) {
    msg.clear();
    p = msg.begin();

    for (char ch : input) {
      if (ch == '[') {
        // the first character when '[' is found
        p = msg.begin();
      } else if (ch == ']') {
        // the end of the message (always)
        p = msg.end();
      } else {
        msg.insert(p, ch);
      }
    }

    for (char ch : msg)
      cout << ch;
    cout << endl;
  }
  return 0;
}