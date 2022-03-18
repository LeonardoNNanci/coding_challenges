#include <bits/stdc++.h>

using namespace std;

vector<int> adj[500];
vector<int> ages;
vector<bool> vis;
int min_age;

void DFS(int u) {
  vis[u] = true;
  min_age = min(min_age, ages[u]);
  for (auto v : adj[u]) {
    if (!vis[v])
      DFS(v);
  }
}

int main(int argc, char const* argv[]) {
  int V, E, c;
  while (cin >> V >> E >> c) {
    ages.assign(V, 0);
    for (int j = 0; j < V; j++) {
      adj[j].clear();
    }

    for (int k = 0; k < V; k++)
      cin >> ages[k];

    while (E--) {
      int u, v;
      cin >> u >> v;
      adj[--v].push_back(--u);
    }

    char instr;
    int A, B;
    while (c--) {
      cin >> instr >> A;
      A--;
      if (instr == 'T') {
        cin >> B;
        B--;
        for (auto& neighbors : adj)
          for (int i = 0; i < neighbors.size(); i++)
            if (neighbors[i] == A)
              neighbors[i] = B;
            else if (neighbors[i] == B)
              neighbors[i] = A;
        auto temp = adj[A];
        adj[A] = adj[B];
        adj[B] = temp;

      } else {
        int age = ages[A];
        ages[A] = min_age = INT_MAX;
        vis.assign(V, false);
        DFS(A);
        ages[A] = age;
        min_age == INT_MAX ? cout << '*' : cout << min_age;
        cout << endl;
      }
    }
  }
  return 0;
}