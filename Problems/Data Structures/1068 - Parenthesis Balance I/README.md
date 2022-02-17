# Parenthesis Balance I

### [Problem description](https://www.beecrowd.com.br/judge/en/problems/view/1068).

### Solution

Use a stack to keep track of parenthesis. Push when opening parenthesis and pop when closing.

Since the stack only stores opening parenthesis, it can be replaced by a counter representing the size of the stack. Incrementing by one when pushing and decrementing by one when popping.

- If the stack size is ever less than 0, the equation is incorrect (closing parenthesis without an opening one).
- After processing the input equation:
  -  if the stack size is greater than 0, it is incorrect (opening parenthesis without a closing one).
  - if the stack size is 0, it is correct (there's an opening parenthesis for every closing one).
