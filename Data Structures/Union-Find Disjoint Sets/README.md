# Union-Find Disjoint Sets

Data Structure used to unite two sets and to efficiently determine if two items belong to the same set.

Implementation based on the book _Competitive Programming 3_ by Steven Halim.

Each disjoint set is represented by one of its elements, in a tree-like structure. The representative item is the root node and the other items are connected to the root directly or indirecty.

To check if two items belong to the same set, the roots of both trees are compared.

To unite two sets, the root of the tallest tree becomes the parent of the other (union by rank heuristic).

Path compression: when searching for the root node, all items in the path traversed, from the item to the root, are parented to the root. This makes the tree wider than taller, improving performance.