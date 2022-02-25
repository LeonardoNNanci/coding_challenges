# Screws and Nuts

### [Problem description](https://www.beecrowd.com.br/judge/en/problems/view/1520).

### Solution

Use and array to accumulate the frequency of each number. Using the frequencies of all numbers smaller than or equal to __num__, it is possible to tell the positions of the first and last apperances of __num__.

Could have used Fenwick Tree, but since there is only one query per test case, it would have been overkill. 
