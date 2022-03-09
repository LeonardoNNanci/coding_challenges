INACTIVE = 0
ACTIVE = 1
DONE = 2

has_cycle = False


def DFS_aux(adj, status, u):
    global has_cycle
    status[u] = ACTIVE
    for v in adj[u]:
        if status[v] == INACTIVE and not has_cycle:
            DFS_aux(adj, status, v)
        elif status[v] == ACTIVE:
            has_cycle = True
    status[u] = DONE


def DFS(adj):
    global has_cycle
    V = len(adj)
    status = [INACTIVE] * V

    for u in range(V):
        if status[u] != DONE and not has_cycle:
            DFS_aux(adj, status, u)


T = int(input())
for _ in range(T):
    V, E = map(int, input().split())
    adj = [[] for _ in range(V)]

    for _ in range(E):
        u, v = map(int, input().split())
        adj[u - 1].append(v - 1)

    has_cycle = False
    DFS(adj)
    print("SIM") if has_cycle else print("NAO")
