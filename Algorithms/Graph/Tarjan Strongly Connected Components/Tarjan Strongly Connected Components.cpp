#define UNVISITED -1

typedef vector<int> vi;

int dfsCount;
vi num, low, visited, adj[MAX_V];
stack<int> S;

void tarjan_SCC(int u) {
  low[u] = num[u] = dfsCounter++;
  S.push(u);
  visited[u] = 1;

  for (auto v : adj[u]) {
    if (num[v.first] == UNVISITED)
      tarjan_SCC(v.first);
    if (visited[v.first])
      low[u] = min(low[u], low[v.first]);
  }

  if (low[u] == num[u]) {
    // new SCC
    int v;
    do {
      v = S.top();
      S.pop();
      visited[v] = 0;
      // add v to the SCC
    } while (u != v);
  }
}

// inside int main()
num.assign(V, UNVISITED);
low.assign(V, 0);
visited.assign(V, 0);
dfsCounter = 0;
for (int i = 0; i < V; i++)
  if (num[i] == UNVISITED)
    tarjan_SCC(i);
