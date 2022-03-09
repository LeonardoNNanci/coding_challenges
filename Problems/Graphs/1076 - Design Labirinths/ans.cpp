#include <bits/stdc++.h>

using namespace std;

int cc_size;

void DFS_aux(vector<int> adj[], bool vis[], int u) {
  cc_size++;
  vis[u] = true;
  for (int edge : adj[u]) {
    if (!vis[edge])
      DFS_aux(adj, vis, edge);
  }
}

void DFS(vector<int> adj[], int V, int n) {
  bool vis[V];
  fill(vis, vis + V, false);

  DFS_aux(adj, vis, n);
}

int main(int argc, char const* argv[]) {
  int T;
  cin >> T;
  while (T--) {
    int n, V, E, u, v;
    cin >> n >> V >> E;

    cc_size = 0;
    vector<int> adj[V];
    for (int i = 0; i < E; i++) {
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    DFS(adj, V, n);
    cout << (cc_size - 1) * 2 << endl;
  }
  return 0;
}