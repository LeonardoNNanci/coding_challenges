typedef pair<int, int> ii;

void DFS_aux(vector<ii> adj[], bool vis[], int u)
{
    cout << "AUX - " << u << endl;
    vis[u] = true;
    for (ii edge : adj[u])
    {
        if (!vis[edge.first])
            DFS_aux(adj, vis, edge.first);
    }
}

void DFS(vector<ii> adj[], int V)
{

    bool vis[V];
    fill(vis, vis + V, false);

    for (int u = 0; u < V; u++)
    {
        if (!vis[u])
        {
            cout << "DFS - " << u << endl;
            DFS_aux(adj, vis, u);
        }
    }
}