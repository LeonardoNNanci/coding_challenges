#include <bits/stdc++.h>

using namespace std;

typedef pair<int, pair<int, int>> iii;

int main(int argc, char const* argv[]) {
  int n, m, v, c;
  priority_queue<iii, vector<iii>, greater<iii>> cashiers;

  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> v;
    cashiers.push(iii(0, {i, v}));
  }

  for (int i = 0; i < m; i++) {
    cin >> c;
    iii cashier = cashiers.top();
    cashiers.pop();
    cashier.first += c * cashier.second.second;
    cashiers.push(cashier);
  }

  while (cashiers.size() > 1) {
    cashiers.pop();
  }

  cout << cashiers.top().first << endl;

  return 0;
}
