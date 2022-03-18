def DFS(u):
    global min_age
    vis[u] = True
    min_age = min(min_age, ages[pos2id[u]])
    for v in adj[u]:
        if not vis[v]:
            DFS(v)


while True:
    try:
        V, E, c = map(int, input().split())
        ages = list(map(int, input().split()))

        adj = [[] for _ in range(V)]
        id2pos = [i for i in range(V)]
        pos2id = [i for i in range(V)]
        for _ in range(E):
            u, v = map(int, input().split())
            adj[v - 1].append(u - 1)

        for _ in range(c):
            items = input().split()
            if len(items) == 3:
                A, B = map(int, items[1:])
                A -= 1
                B -= 1
                pos2id[id2pos[A]], pos2id[id2pos[B]] = (
                    pos2id[id2pos[B]],
                    pos2id[id2pos[A]],
                )
                id2pos[A], id2pos[B] = id2pos[B], id2pos[A]

            else:
                A = int(items[1]) - 1
                min_age = float("inf")
                temp, ages[A] = ages[A], float("inf")
                vis = [False] * V
                DFS(id2pos[A])
                ages[A] = temp
                print("*") if min_age == float("inf") else print(min_age)

    except EOFError:
        break
