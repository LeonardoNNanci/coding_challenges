MAX_V = 105

adj = [[] for _ in range(MAX_V)]


def DFS(u):
    vis[u] = True
    for v in adj[u]:
        if not vis[v]:
            DFS(v)


T = int(input())
for t in range(1, T + 1):
    line = input().split()
    if len(line) == 1:
        V = int(line[0])
        E = int(input())
    else:
        V, E = map(int, input().split())

    for i in range(V):
        adj[i].clear()

    for _ in range(E):
        u, v = map(lambda x: int(x) - 1, input().split())
        adj[u].append(v)
        adj[v].append(u)

    count = 0
    vis = [False] * V
    for u in range(V):
        if not vis[u]:
            count += 1
            DFS(u)

    print(f"Caso #{t}: ", end="")
    if count <= 1:
        print("a promessa foi cumprida")
    else:
        print(f"ainda falta(m) {count-1} estrada(s)")
