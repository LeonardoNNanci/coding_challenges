#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int A, B;

int invert(int x) {
  int last_digit, inv = 0;
  while (x > 0) {
    last_digit = x % 10;
    inv = (inv * 10) + last_digit;
    x /= 10;
  }
  return inv;
}

int BFS() {
  set<int> vis;
  queue<ii> q;
  q.push({A, 0});
  int count = 0;
  while (!q.empty()) {
    int u = q.front().first;
    int dist = q.front().second;
    q.pop();

    if (vis.find(u) != vis.end())
      continue;
    if (u == B)
      return dist;
    vis.insert(u);

    int inv = invert(u);
    if (vis.find(inv) == vis.end())
      q.push({inv, dist + 1});
    if (vis.find(u + 1) == vis.end())
      q.push({u + 1, dist + 1});
  }
  return -1;
}

int main(int argc, char const* argv[]) {
  int T;
  cin >> T;
  while (T--) {
    cin >> A >> B;
    cout << BFS() << endl;
  }
  return 0;
}