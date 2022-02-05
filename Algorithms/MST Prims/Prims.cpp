typedef pair<int, int> ii;
typedef vector<ii> vii;

// type stored in priority queue
struct UVW
{
    int u, v, w;
    bool operator>(const UVW &other) const
    {
        return w > other.w;
    }
};

void prims_MST(vii graph[], int V)
{
    int u = 0, n = 1;
    vector<bool> viz(V, false);
    priority_queue<UVW, vector<UVW>, greater<UVW>> pq;

    while (n < V)
    {
        if (!viz[u])
        {
            viz[u] = true;
            for (auto edge : graph[u])
                if (!viz[edge.first])
                    pq.push({u, edge.first, edge.second});
        }

        auto p = pq.top();
        pq.pop();

        if (!viz[p.v])
        {
            // adds edge (p.u---p.v) to solution
            u = p.v;
            n++;
        }
    }
}