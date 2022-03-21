# Belman-Ford Single Source Shortest Path - O(V E)

Complete search algorithm that relaxes the edges V-1 times to find the shortest path.

The idea behind relaxation is: if the path to __v__ passing through the current edge __u__ is shorter than the previous path to __u__, update the distance to __u__.

The algorithm does that V-1 times because the shortest path will never have a cycle and, therefore, the path to the furthest vertex is V-1 edges long.

This algorithm is useful to detect negative cycles in a graph and to solve SSSP problems whose graphs are small, due to the short implementation.