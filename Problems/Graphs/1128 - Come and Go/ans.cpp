#include <bits/stdc++.h>
#define UNVISITED -1
#define MAX_V 2005

using namespace std;

typedef vector<int> vi;

int dfsCounter, countSCC;
vi num, low, visited, adj[MAX_V];
stack<int> S;

void tarjan_SCC(int u) {
  low[u] = num[u] = dfsCounter++;
  S.push(u);
  visited[u] = 1;

  for (auto v : adj[u]) {
    if (num[v] == UNVISITED)
      tarjan_SCC(v);
    if (visited[v])
      low[u] = min(low[u], low[v]);
  }

  if (low[u] == num[u]) {
    countSCC++;
    int v;
    do {
      v = S.top();
      S.pop();
      visited[v] = 0;
    } while (u != v);
  }
}

int main(int argc, char const* argv[]) {
  int V, E, u, v, p;

  while (true) {
    cin >> V >> E;
    if (!(V || E))
      break;

    while (E--) {
      cin >> u >> v >> p;
      u--;
      v--;
      adj[u].push_back(v);
      if (p == 2)
        adj[v].push_back(u);
    }

    num.assign(V, UNVISITED);
    low.assign(V, 0);
    visited.assign(V, 0);
    dfsCounter = countSCC = 0;
    for (int i = 0; i < V; i++)
      if (num[i] == UNVISITED)
        tarjan_SCC(i);

    cout << (countSCC == 1) << endl;

    for (int i = 0; i < V; i++)
      adj[i].clear();
  }
  return 0;
}