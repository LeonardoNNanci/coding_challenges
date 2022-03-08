#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

vector<int> component;

void DFS_aux(vector<int> adj[], bool vis[], int u) {
  vis[u] = true;
  component.push_back(u);
  for (int edge : adj[u]) {
    if (!vis[edge])
      DFS_aux(adj, vis, edge);
  }
}

void DFS(vector<int> adj[], int V) {
  bool vis[V];
  fill(vis, vis + V, false);

  int count = 0;
  for (int u = 0; u < V; u++) {
    if (!vis[u]) {
      count++;
      component.clear();

      DFS_aux(adj, vis, u);
      sort(component.begin(), component.end());
      for (auto v : component)
        cout << (char)('a' + v) << ',';
      cout << endl;
    }
  }
  cout << count << " connected components" << endl;
}

int main(int argc, char const* argv[]) {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int V, E;
    char u, v;
    cin >> V >> E;
    vector<int> adj[V];

    for (int j = 0; j < E; j++) {
      cin >> u >> v;
      u -= 'a';
      v -= 'a';
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    cout << "Case #" << i << ':' << endl;
    DFS(adj, V);
    cout << endl;
  }
  return 0;
}
