# Dijkstra's Shortest Path - O(E log V)

Greedy algorithm that, starting from the source vertex, traverses the graph picking the least distant vertex reachable from the visited vertices. For each vertex __v__ reachable from the current vertex __u__, update the distance from the source to __v__ if the path passing through __u__ is shorter than the previous known path.