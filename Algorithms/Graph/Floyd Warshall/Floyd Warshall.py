# in main
# adjacency MATRIX
# INF representing edges that don't exist

for k in range(V):
    for i in range(V):
        for j in range(V):
            adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j])
