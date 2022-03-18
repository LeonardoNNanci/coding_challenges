#include <bits/stdc++.h>

using namespace std;

vector<int> adj[100];
bitset<100> vis;

void DFS(int u) {
  vis.set(u);
  for (auto v : adj[u]) {
    if (!vis.test(v))
      DFS(v);
  }
}

int main(int argc, char const* argv[]) {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int V, E, u, v;
    cin >> V >> E;

    for (int i = 0; i < V; i++)
      adj[i].clear();

    for (int i = 0; i < E; i++) {
      cin >> u >> v;
      adj[--u].push_back(--v);
      adj[v].push_back(u);
    }

    int count = 0;
    vis.reset();
    for (int u = 0; u < V; u++)
      if (!vis.test(u)) {
        DFS(u);
        count++;
      }

    cout << "Caso #" << t << ": ";
    count > 1 ? cout << "ainda falta(m) " << count - 1 << " estrada(s)"
              : cout << "a promessa foi cumprida";
    cout << endl;
  }
  return 0;
}