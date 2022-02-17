# Fenwick Tree

Data Structure useful for efficient querying and updating dynamic cumulative tables: both operations in O(log n).

Data is structured in an array storing the cumulative values. The least significant 1 bit of each index defines how many values are accumulated in that index. For example, indices 3(b0011) and 5(b0101) accumulate only one value, while index 4(b0100) accumulates four and index 6(b0110) accumulates two.

Query methods are called using 0 indexing, while the actual algorithms use 1 indexing.

When querying for an interval [1, high], the data structure accumulates the values in indices from high to 0, switching the least significant 1 bit to 0 at each iteration. That is, for interval [1, 6], it accumulates values in indices 6(b0110) and 4(b0100). Next index is 0(b0000), so it's done.

When querying for an interval [low, high], with low != 1, the data structure queries for [1, high] and then "removes" the value returned from query [1, low].

When updating a value, the data structure updates all indices that accumulate the given value, by adding the least significant 1 bit to the index on each iteration. For example, updating index 5(b0101), indices 6(b0110), 8(b1000), until the index is greater then the structure array.