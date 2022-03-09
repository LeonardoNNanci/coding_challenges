#include <bits/stdc++.h>

using namespace std;

#define INACTIVE 0
#define ACTIVE 1
#define DONE 2

bool has_cycle;

void DFS_aux(vector<int> adj[], short int status[], int u) {
  status[u] = ACTIVE;
  for (int v : adj[u]) {
    if (status[v] == INACTIVE and !has_cycle)
      DFS_aux(adj, status, v);
    else if (status[v] == ACTIVE)
      has_cycle = true;
  }
  status[u] = DONE;
}

void DFS(vector<int> adj[], int V) {
  short int status[V];
  fill(status, status + V, INACTIVE);
  for (int u = 0; u < V; u++) {
    if (status[u] != DONE) {
      DFS_aux(adj, status, u);
    }
  }
}

int main(int argc, char const* argv[]) {
  int T;
  cin >> T;
  while (T--) {
    int N, M, u, v;
    cin >> N >> M;
    vector<int> adj[N];

    while (M--) {
      cin >> u >> v;
      adj[u - 1].push_back(v - 1);
    }

    has_cycle = false;
    DFS(adj, N);
    has_cycle ? cout << "SIM" : cout << "NAO";
    cout << endl;
  }

  return 0;
}
