#include <bits/stdc++.h>

using namespace std;

typedef pair<bool, string> p;

int main() {
  set<pair<bool, string>> registered;
  string name;
  string status;

  int max = 0;
  string winner;

  while (true) {
    cin >> name;
    if (name == "FIM")
      break;

    cin >> status;
    registered.insert(p((status != "YES"), name));
    if (status == "YES" && name.size() > max) {
      max = name.size();
      winner = name;
    }
  }

  for (auto p : registered) {
    cout << p.second << '\n';
  }
  cout << "\nAmigo do Habay:\n" << winner << '\n';

  return 0;
}