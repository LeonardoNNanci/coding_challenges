# Segment Tree

Data Structure used to efficiently answer dynamic range queries in arrays: O(log n) instead of O(n).

The data is structured in a tree whose nodes represent the query answer in different ranges. The root node represents the entire array. Left children represent the left half of their parent array and right children represent their parents' right half array.

When searching for the answer to a query in range [low, high], the data structure looks for nodes representing the ranges [low, \_] and [\_, high], then takes the "best" of those values to solve the problem.

To modify it according to the problem to be solved, it is necessary to define: 
- the _neutral_ variable to some value which will lose to/won't modify any other value in the problem set.
- the _op_ method to some operation to chose the "best" value between the two child nodes.