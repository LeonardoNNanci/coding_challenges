# Ants Colony

### [Problem description](https://www.beecrowd.com.br/judge/en/problems/view/1135).

### Solution

Since the graph is a tree, it can be stored in a vector of parents, instead of adjacency matrix or adjacency list.

For this problem, also store two more vectors, the weight to each parent and the depth of the nodes in the tree.

To find the distance between nodes, find their deepest common ancestor, accumulating the edge weights in the search.

Python code exceeded the time limit.