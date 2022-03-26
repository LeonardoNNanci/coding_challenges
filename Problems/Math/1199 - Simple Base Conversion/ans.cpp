#include <bits/stdc++.h>

using namespace std;

int main() {
  while (true) {
    string str;
    cin >> str;

    if (str == "-1")
      break;
    if (str.substr(0, 2) == "0x") {
      str = str.substr(2, str.length() - 2);
      int x;
      stringstream ss;
      ss << hex << str;
      ss >> x;
      cout << dec << x << endl;
    } else {
      int x = stoi(str);
      cout << "0x" << uppercase << hex << x << endl;
    }
  }

  return 0;
}
