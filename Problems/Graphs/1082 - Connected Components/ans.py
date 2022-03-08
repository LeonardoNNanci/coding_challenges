global component
A = ord("a")


def DFS_aux(adj, vis, u):
    global component
    component.append(u)

    vis[u] = True
    for v in adj[u]:
        if not vis[v]:
            DFS_aux(adj, vis, v)


def DFS(adj):
    global component
    V = len(adj)

    vis = [False] * V

    count = 0
    for u in range(V):
        if not vis[u]:
            count += 1
            component = []

            DFS_aux(adj, vis, u)
            component.sort()

            for v in component:
                print(f"{chr(v + A)},", end="")
            print()
    print(f"{count} connected components\n")


n = int(input())
for i in range(1, n + 1):
    V, E = map(int, input().split())
    adj = [[] for _ in range(V)]

    for _ in range(E):
        u, v = map(lambda x: ord(x) - A, input().split())
        adj[u].append(v)
        adj[v].append(u)

    print(f"Case #{i}:")
    DFS(adj)
