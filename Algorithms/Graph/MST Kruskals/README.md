# Kruskal's Minimum Spanning Tree - O(E log V)

Greedy algorithm that takes a list of edges as input, sorts it in increasing order of weights, then takes the minimum weighted edge not yet taken and, if its origin or destiny vertices aren't in the solution yet, adds to the solution. 