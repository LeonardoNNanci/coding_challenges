// in main
vector<int> dist(V, INT_MAX);
dist[s] = 0;
for (int i = 0; i < V - 1; i++)
  for (int u = 0; u < V; u++)
    for (auto [v, w] : adj[u])
      dist[v] = min(dist[v], dist[u] + w);
