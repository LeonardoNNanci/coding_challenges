#include <bits/stdc++.h>

using namespace std;

int c;
vector<pair<int, int>> adj[250];

typedef pair<int, int> ii;

int dijkstra(int src, int dest, int V) {
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
      if (dist[v] > d + w && (u >= c || (u < c && v == u + 1))) {
        dist[v] = d + w;
        parent[v] = u;
        pq.push(ii(dist[v], v));
      }
    }
  }

  return -1;
}

int main(int argc, char const* argv[]) {
  while (true) {
    int V, E, k, u, v, w;
    cin >> V >> E >> c >> k;
    if (!(V || E || c || k))
      break;

    for (int i = 0; i < V; i++)
      adj[i].clear();

    while (E--) {
      cin >> u >> v >> w;
      adj[u].push_back({v, w});
      adj[v].push_back({u, w});
    }

    cout << dijkstra(k, c - 1, V) << endl;
  }

  return 0;
}