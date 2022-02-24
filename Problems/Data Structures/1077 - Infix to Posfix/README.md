# Infix to Posfix

### [Problem description](https://www.beecrowd.com.br/judge/en/problems/view/1077).

### Solution

Use stack to help build posfix equation. Parse the string from left to right, folowing the rules:

- if the character is a variable or a number, print it;
- if the character is '(', push it to the stack;
- if the character is ')', pop from the stack until the value on the top is '(';
- if the character is an operation, pop from the stack until the value on the top is an operation with lower priority;
- after parsing the equation, print the values in the stack.