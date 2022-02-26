#include <bits/stdc++.h>

using namespace std;

typedef pair<int, pair<int, pair<float, string>>> info;

int main(int argc, char const* argv[]) {
  string name;
  float height;
  int weight, age, t, n, m;

  cin >> t;
  for (int c = 1; c <= t; c++) {
    cin >> n >> m;
    vector<info> elves(n);

    for (int i = 0; i < n; i++) {
      cin >> name >> weight >> age >> height;
      elves[i] = info(-weight, {age, {height, name}});
    }

    sort(elves.begin(), elves.end());

    cout << "CENARIO {" << c << '}' << endl;
    for (int i = 0; i < m; i++) {
      name = elves[i].second.second.second;
      cout << i + 1 << " - " << name << endl;
    }
  }
  return 0;
}