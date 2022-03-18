# Boss

### [Problem description](https://www.beecrowd.com.br/judge/en/problems/view/1469).

### Solution

Build the graph in inverse order of management (managed->manager). When swapping positions, swap all apperances of the ids in the adjacency matrix and each other's neighbors. When querying for the youngest manager, perform a [Depth First Search](https://github.com/LeonardoNNanci/coding_challenges/tree/main/Algorithms/Graph/Depth%20First%20Search) going from the employee to the top manager.

Python code exceeded the time limit.