# Connected Components

### [Problem description](https://www.beecrowd.com.br/judge/en/problems/view/1082).

### Solution

Use [Depth First Search](https://github.com/LeonardoNNanci/coding_challenges/tree/main/Algorithms/Graph/Depth%20First%20Search) to traverse the graph. Every time a new vertex is the source of a new DFS traversal, it is the source of a new connected component.

While traversing, store vertices in an array, then, after completing the traverse, sort the array and print the component.