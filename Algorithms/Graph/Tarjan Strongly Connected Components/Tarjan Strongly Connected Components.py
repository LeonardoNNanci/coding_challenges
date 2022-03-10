from collections import deque

UNVISITED = -1


def tarjan_SCC(u):
    low[u] = num[u] = dfsCounter
    dfsCounter += 1
    S.append(u)
    visited[u] = True

    for v, w in adj[u]:
        if num[v] == UNVISITED:
            tarjan_SCC(v)
        if visited[v]:
            low[u] = min(low[u], low[v])

    if low[u] == num[u]:
        # new SCC
        while 1:
            v = S.pop()
            visited[v] = False
            # add v to the SCC
            if u == v:
                break


# inside main
S = deque()
low = [0] * V
visited = [True] * V
num = [UNVISITED] * V
dfsCounter = 0
for i in range(V):
    if num[i] == UNVISITED:
        tarjan_SCC(i)
