#include <bits/stdc++.h>

#define TAB "  "

using namespace std;

void DFS_aux(vector<int> adj[], bool vis[], int u, int depth) {
  vis[u] = true;
  for (int v : adj[u]) {
    for (int i = 0; i < depth; i++)
      cout << TAB;
    cout << u << '-' << v;
    if (!vis[v]) {
      cout << " pathR(G," << v << ')' << endl;
      DFS_aux(adj, vis, v, depth + 1);
    } else
      cout << endl;
  }
}

void DFS(vector<int> adj[], int V) {
  bool vis[V];
  fill(vis, vis + V, false);

  for (int u = 0; u < V; u++)
    if (!vis[u] and !adj[u].empty()) {
      DFS_aux(adj, vis, u, 1);
      cout << endl;
    }
}

int main(int argc, char const* argv[]) {
  int n, u, v, E, V;
  cin >> n;
  for (int c = 1; c <= n; c++) {
    cin >> V >> E;
    vector<int> adj[V];
    while (E--) {
      cin >> u >> v;
      adj[u].push_back(v);
      // adj[v].push_back(u);
    }

    for (auto& neighbors : adj)
      sort(neighbors.begin(), neighbors.end());

    cout << "Caso " << c << ':' << endl;
    DFS(adj, V);
  }

  return 0;
}