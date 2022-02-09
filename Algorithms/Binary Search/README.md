# Binary Search - O(log n)
Divide and Conquer algorithm that searches for a given value x in a sorted array arr and returns its index or -1 when not found.

Takes advantage of the sorted array to only search for x in indexes where it can actually be stored, reducing the search area in half every iteration x is not found.