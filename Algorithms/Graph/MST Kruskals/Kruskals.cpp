typedef tuple<int, int, int> iii;

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