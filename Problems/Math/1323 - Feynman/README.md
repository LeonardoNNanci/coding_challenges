# Feynman

### [Problem description](https://www.beecrowd.com.br/judge/en/problems/view/1323).

### Solution

The number of squares in a nxn square is:
- 1x1 squares: n<sup>2</sup>
- 2x2 squares: (n-1)<sup>2</sup>
- 3x3 squares: (n-2)<sup>2</sup>

And so on until:
- nxn squares: 1

To solve the problem, pre-process indutively an array storing the total number of squares in nxn squares, with n from 1 to 100. Then print the desired values from the array.