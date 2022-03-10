from collections import deque

UNVISITED = -1


def tarjan_SCC(u):
    global dfsCounter, countSCC
    low[u] = num[u] = dfsCounter
    dfsCounter += 1
    S.append(u)
    visited[u] = True

    for v in adj[u]:
        if num[v] == UNVISITED:
            tarjan_SCC(v)
        if visited[v]:
            low[u] = min(low[u], low[v])

    if low[u] == num[u]:
        countSCC += 1
        while 1:
            v = S.pop()
            visited[v] = False
            if u == v:
                break


# inside main
while True:
    V, E = map(int, input().split())
    if not (V or E):
        break

    adj = [[] for _ in range(V)]

    for _ in range(E):
        u, v, p = map(int, input().split())
        u -= 1
        v -= 1
        adj[u].append(v)
        if p == 2:
            adj[v].append(u)

    S = deque()
    low = [0] * V
    visited = [True] * V
    num = [UNVISITED] * V
    dfsCounter = countSCC = 0
    for i in range(V):
        if num[i] == UNVISITED:
            tarjan_SCC(i)

    print(int(countSCC == 1))
