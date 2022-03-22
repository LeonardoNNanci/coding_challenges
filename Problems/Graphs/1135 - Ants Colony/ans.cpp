#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int orig, dest;
vector<ii> parent;
vector<int> depth;

int main(int argc, char const* argv[]) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  while (true) {
    int V, v, w;
    cin >> V;
    if (!V)
      break;

    parent.assign(V, ii(-1, 0));
    depth.assign(V, 0);

    for (int u = 1; u < V; u++) {
      cin >> v >> w;
      parent[u] = ii(v, w);
      depth[u] = depth[v] + 1;
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
      if (i)
        cout << ' ';
      cin >> orig >> dest;
      long long dist = 0;

      int deepest = depth[orig] >= depth[dest] ? orig : dest;
      int highest = depth[orig] < depth[dest] ? orig : dest;

      while (depth[deepest] > depth[highest]) {
        dist += parent[deepest].second;
        deepest = parent[deepest].first;
      }

      orig = deepest, dest = highest;

      while (orig != dest) {
        dist += parent[orig].second + parent[dest].second;
        orig = parent[orig].first;
        dest = parent[dest].first;
      }
      cout << dist;
    }
    cout << endl;
  }
  return 0;
}