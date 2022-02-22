def kruskals_MST(edges, V, E):
    uf = UnionFind(V)
    edges.sort()

    mst_cost = 0
    for w, u, v in edges:
        if not uf.is_same_set(u, v):
            mst_cost += w
            uf.union_set(u, v)

    return mst_cost
