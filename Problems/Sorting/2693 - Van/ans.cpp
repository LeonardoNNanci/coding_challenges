#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const* argv[]) {
  int n, dist;
  while (cin >> n) {
    char region;
    string name;
    vector<pair<int, pair<char, string>>> people(n);
    for (int i = 0; i < n; i++) {
      cin >> name >> region >> dist;
      people[i] = pair<int, pair<char, string>>(dist, {region, name});
    }

    sort(people.begin(), people.end());
    for (auto p : people)
      cout << p.second.second << endl;
  }
  return 0;
}
