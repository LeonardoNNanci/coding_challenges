typedef pair<int, int> ii;

int dijkstra(vector<ii> adj[], int src, int dest, int V) {
  int dist[V], parent[V];
  priority_queue<ii, vector<ii>, greater<ii>> pq;

  fill(dist, dist + V, INT_MAX);
  fill(parent, parent + V, -1);

  dist[src] = 0;
  pq.push(ii(dist[src], src));

  while (!pq.empty()) {
    int d = pq.top().first;
    int u = pq.top().second;
    pq.pop();

    if (u == dest)
      return d;
    if (d > dist[u])
      continue;

    for (ii edge : adj[u]) {
      int v = edge.first;
      int w = edge.second;
      if (dist[v] > d + w) {
        dist[v] = d + w;
        parent[v] = u;
        pq.push(ii(dist[v], v));
      }
    }
  }

  return -1;
}