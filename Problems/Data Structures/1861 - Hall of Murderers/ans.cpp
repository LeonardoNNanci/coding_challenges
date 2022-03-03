#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const* argv[]) {
  set<string> dead_list;
  string killer, killed;
  map<string, int> death_count;

  while (cin >> killer >> killed) {
    dead_list.insert(killed);
    death_count[killer]++;
  }

  cout << "HALL OF MURDERERS" << endl;
  for (auto p : death_count) {
    if (dead_list.find(p.first) != dead_list.end())
      cout << p.first << ' ' << p.second << endl;
  }

  return 0;
}
