# Boss

### [Problem description](https://www.beecrowd.com.br/judge/en/problems/view/1469).

### Solution

Build the graph in inverse order of management (managed->manager). When swapping positions, swap all apperances of the ids in the adjacency matrix and each other's neighbors. When querying for the youngest manager, perform a [Depth First Search](https://github.com/LeonardoNNanci/coding_challenges/tree/main/Algorithms/Graph/Depth%20First%20Search) going from the employee to the top manager.

Python code exceeded the time limit.

<hr>

__Update:__

Python code accepted.

Modified Python code to keep track of which employees are in each position in the graph. Now instead of going through all edges to swap positions in O(V+E), just update their position in the list in O(1).