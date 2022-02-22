typedef pair<int, int> ii;

void primsMST(vector<ii> adj[], int V)
{
    int src = 0;
    bool MSTset[V];
    int weights[V], parents[V];
    priority_queue<ii, vector<ii>, greater<ii>> pq;

    fill(MSTset, MSTset + V, false);
    fill(weights, weights + V, INT_MAX);
    fill(parents, parents + V, -1);

    weights[src] = 0;
    pq.push(make_pair(weights[src], src));

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        if (MSTset[u])
            continue;

        MSTset[u] = true;

        for (ii edge : adj[u])
        {
            int v = edge.first;
            int w = edge.second;
            if (!MSTset[v] && weights[v] > w)
            {
                pq.push(make_pair(w, v));
                weights[v] = w;
                parents[v] = u;
            }
        }
    }
}