#define MAX_V 1000

typedef pair<int, int> ii;

vector<ii> adj[MAX_V];
bitset<MAX_V> vis;

void DFS_aux(int u) {
  vis.set(u);
  for (auto edge : adj[u]) {
    if (!vis.test(edge.first))
      DFS_aux(edge.first);
  }
}

// in main
vis.reset();
for (int u = 0; u < V; u++)
  if (!vis.test(u))
    DFS(u);
