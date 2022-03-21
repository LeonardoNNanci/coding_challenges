# Floyd-Warshall All Pairs Shortest Paths - O(V<sup>3</sup>)

Dynamic programming algorithm that gradually allows the use of intermediate vertices along the paths between pairs of vertices. Update the distance values id the path using the new intermediate vertice is shorter than the previous one.

This algorithm is fast to implement, but should only be used in small graphs, due to its complexity.