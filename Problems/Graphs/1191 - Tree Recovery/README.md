# Tree Recovery

### [Problem description](https://www.beecrowd.com.br/judge/en/problems/view/1191).

### Solution

Pick the first element _E_ from the preorder string, find its index _i_ in the inorder string.

Every element on the left of _i_ in inorder is on the left subtree of _E_ in the tree. Every element on the right of _i_ in inorder is on the right subtree of _E_ in the tree.

Recursively call the procedure for the left and right subarrays, increasing the index of element _E_ (of preorder) to find in the sub arrays.

After backtracking, add the character to the post order solution.