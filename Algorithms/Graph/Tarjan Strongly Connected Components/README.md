# Tarjan Strongly Connected Components - O(V + E)

Algorithm that, in directed graphs, finds strongly connected components (SCCs). That is: given vertices _u_ and _v_ in the SCC, it is possible to get from _u_ to _v_ __and__ from _v_ to _u_.

Perform a [Depth First Search]() on the graph, storing:
- in __num__ the the number of the first iteration in which the vertex is reached;
- in __low__ the lowest __num__ reached by the current DFS subtree;
- in __visited__ if the vertex has been visited.

Vertices with lower num are ancestors of those with higher num.

Push _u_ to a stack.

Only update __low__ if the neighbor _v_ is marked as visited, to avoid updating _u_ in cases _u_ can reach _v_, but _v_ cant reach _u_.

If low[v] $\le$ num[u], _u_ they are in the same SCC.

If low[u] = num[u], then u is the root of the SCC. Pop from the stack until _u_, marking the vertices as unvisited.