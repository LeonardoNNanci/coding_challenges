typedef pair<int, pair<int, int>> iii;

int kruskals_MST(vector<iii> edges, int V, int E) {
  UnionFind uf(V);
  sort(edges.begin(), edges.end());

  int mst_cost = 0;
  for (int i = 0; i < E; i++) {
    int w = edges[i].fisrt;
    int u = edges[i].second.first;
    int v = edges[i].second.second;

    if (!uf.isSameSet(u, v)) {
      mst_cost += w;
      uf.unionSet(u, v);
    }
  }
  return mst_cost;
}