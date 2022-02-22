typedef pair<int, int> ii;

void BFS(vector<ii> adj[], int V)
{

    bool vis[V];
    fill(vis, vis + V, false);
    queue<int> q;
    q.push(0);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        if (vis[u])
            continue;
        vis[u] = true;

        for (ii edge : adj[u])
        {
            if (!vis[edge.first])
                q.push(edge.first);
        }
    }
}