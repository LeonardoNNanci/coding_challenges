#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int adj[500][500];

int dijkstra(int src, int dest, int V) {
  int dist[V];
  priority_queue<ii, vector<ii>, greater<ii>> pq;

  fill(dist, dist + V, INT_MAX);

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

    for (int v = 0; v < V; v++) {
      if (adj[u][v] != -1) {
        int w = adj[u][v];
        if (dist[v] > d + w) {
          dist[v] = d + w;
          pq.push(ii(dist[v], v));
        }
      }
    }
  }

  return -1;
}

int main(int argc, char const* argv[]) {
  while (true) {
    int n, e;
    cin >> n >> e;
    if (!(n || e))
      break;

    int x, y, h;

    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        adj[i][j] = -1;

    for (int i = 0; i < e; i++) {
      cin >> x >> y >> h;
      x--;
      y--;
      if (adj[y][x] != -1) {
        adj[x][y] = 0;
        adj[y][x] = 0;
      } else
        adj[x][y] = h;
    }

    int k, o, d, cost;
    cin >> k;
    while (k--) {
      cin >> o >> d;
      o--;
      d--;
      cost = dijkstra(o, d, n);
      if (cost == -1)
        cout << "Nao e possivel entregar a carta" << endl;
      else
        cout << cost << endl;
    }
    cout << endl;
  }

  return 0;
}