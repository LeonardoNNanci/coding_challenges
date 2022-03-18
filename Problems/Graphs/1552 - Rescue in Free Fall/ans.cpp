#include <bits/stdc++.h>

using namespace std;

typedef tuple<float, int, int> iii;

vector<iii> edges;

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

float kruskals_MST(int V, int E) {
  UnionFind uf(V);
  sort(edges.begin(), edges.end());

  float mst_cost = 0;
  for (int i = 0; i < E; i++) {
    int u, v;
    float w;
    tie(w, u, v) = edges[i];

    if (!uf.isSameSet(u, v)) {
      mst_cost += w;
      uf.unionSet(u, v);
    }
  }
  return mst_cost;
}

int main(int argc, char const* argv[]) {
  int C;
  cin >> C;
  while (C--) {
    int V, E;
    cin >> V;
    E = (V + 1) * V / 2;
    vector<pair<float, float>> pos(V);
    edges.assign(E, iii(0, 0, 0));

    for (int i = 0; i < V; i++)
      cin >> pos[i].first >> pos[i].second;

    int count = 0;
    for (int i = 0; i < V; i++)
      for (int j = i + 1; j < V; j++) {
        float dist = sqrt(pow(pos[i].first - pos[j].first, 2) +
                          pow(pos[i].second - pos[j].second, 2));
        edges[count++] = iii(dist, i, j);
      }

    cout.setf(ios::fixed);
    cout << setprecision(2) << kruskals_MST(V, E) / 100 << endl;
  }
  return 0;
}