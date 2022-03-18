# Contamination

### [Problem description](https://www.beecrowd.com.br/judge/en/problems/view/1583).

### Solution

Use [Flood Fill BFS](https://github.com/LeonardoNNanci/coding_challenges/tree/main/Algorithms/Graph/Flood%20Fill) to traverse the grid spreading the contaminant, if the cell is water or contaminant. Use a custom charachter to keep track of visited cells, then replace that character by the contaminant character when printing.