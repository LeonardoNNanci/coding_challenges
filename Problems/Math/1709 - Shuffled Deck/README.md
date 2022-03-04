# Shuffled Deck

### [Problem description](https://www.beecrowd.com.br/judge/en/problems/view/1709).

### Solution

If one element is in position, all elements are in position.

Using 1 indexing and observing the indices of the element 1 on every iteration, one can observe that:
- the index doubles each iteration
- if the index is greater than the number of cards, the index becomes __(index - 1) % n_cards__.

Iterate intil the index is 1 again, then print the total number of iterations.