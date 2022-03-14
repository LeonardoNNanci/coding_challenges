#include <bits/stdc++.h>

using namespace std;
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

    for (ii edge1 : adj[u]) {
      int v1 = edge1.first;
      int w1 = edge1.second;
      for (ii edge2 : adj[v1]) {
        int v2 = edge2.first;
        int w2 = edge2.second;
        if (dist[v2] > d + w1 + w2) {
          dist[v2] = d + w1 + w2;
          parent[v2] = u;
          pq.push(ii(dist[v2], v2));
        }
      }
    }
  }

  return -1;
}
int main(int argc, char const* argv[]) {
  int V, E, u, v, w;
  cin >> V >> E;
  vector<ii> adj[V];
  for (int i = 0; i < E; i++) {
    cin >> u >> v >> w;
    u--;
    v--;
    adj[u].push_back(ii(v, w));
    adj[v].push_back(ii(u, w));
  }
  int cost = dijkstra(adj, 0, V - 1, V);
  cost == INT_MAX ? cout << -1 : cout << cost;
  cout << endl;
  return 0;
}