#include <bits/stdc++.h>

using namespace std;

typedef tuple<int, int, int> iii;

class UnionFind {
 private:
  vector<int> parent, rank;

 public:
  UnionFind(int N) {
    rank.assign(N, 0);
    parent.assign(N, 0);
    for (int i = 0; i < N; i++)
      parent[i] = i;
  }

  int findSet(int i) {
    return parent[i] == i ? i : (parent[i] = findSet(parent[i]));
  }

  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

  void unionSet(int i, int j) {
    if (isSameSet(i, j))
      return;

    int x = findSet(i), y = findSet(j);
    if (rank[x] > rank[y])
      parent[y] = x;
    else {
      parent[x] = y;
      if (rank[x] == rank[y])
        rank[y]++;
    }
  }
};

int kruskals_MST(vector<iii> edges, int V, int E) {
  UnionFind uf(V);
  sort(edges.begin(), edges.end());

  int mst_cost = 0;
  for (int i = 0; i < E; i++) {
    int w, u, v;
    tie(w, u, v) = edges[i];

    if (!uf.isSameSet(u, v)) {
      mst_cost += w;
      uf.unionSet(u, v);
    }
  }
  return mst_cost;
}

int main(int argc, char const* argv[]) {
  int m, n, x, y, z;
  while (true) {
    cin >> m >> n;
    if (!(m || n))
      break;
    int cost = 0;
    vector<iii> edges(n);

    for (int i = 0; i < n; i++) {
      cin >> x >> y >> z;
      cost += z;
      edges[i] = iii(z, x, y);
    }

    cout << cost - kruskals_MST(edges, m, n) << endl;
  }

  return 0;
}
