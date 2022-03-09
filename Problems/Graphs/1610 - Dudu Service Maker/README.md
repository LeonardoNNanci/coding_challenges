# Dudu Service Maker

### [Problem description](https://www.beecrowd.com.br/judge/en/problems/view/1610).

### Solution

Use [Depth First Search](https://github.com/LeonardoNNanci/coding_challenges/tree/main/Algorithms/Graph/Depth%20First%20Search) to detect cycles.

Label the vertices as:
- Inactive if the vertex has not been visited yet;
- Active if the vertex has been visited earlier in the current DFS subtree;
- Done if the DFS call for the vertex has concluded.

If an active vertex is reached in the DFS subtree, there is a cycle.