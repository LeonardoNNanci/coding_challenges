def DFS_aux(adj, vis, u, depth):
    vis[u] = True
    for v in adj[u]:
        for _ in range(depth):
            print("  ", end="")
        print(f"{u}-{v}", end="")
        if not vis[v]:
            print(f" pathR(G,{v})")
            DFS_aux(adj, vis, v, depth + 1)
        else:
            print()


def DFS(adj):
    V = len(adj)

    vis = [False] * V

    for u in range(V):
        if not vis[u] and adj[u]:
            DFS_aux(adj, vis, u, 1)
            print()


n = int(input())
for c in range(1, n + 1):
    V, E = map(int, input().split())
    adj = [[] for i in range(V)]

    for _ in range(E):
        u, v = map(int, input().split())
        adj[u].append(v)

    for neighbors in adj:
        neighbors.sort()

    print(f"Caso {c}:")
    DFS(adj)
