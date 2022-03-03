#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const* argv[]) {
  int n;
  while (true) {
    cin >> n;
    if (!n)
      break;

    map<string, string> signatures;
    string name, original, day;
    while (n--) {
      cin >> name >> original;
      signatures[name] = original;
    }

    int m, count = 0;
    cin >> m;
    while (m--) {
      cin >> name >> day;
      if (signatures[name] == day)
        count++;
    }

    cout << count << endl;
    signatures.clear();
  }
  return 0;
}
