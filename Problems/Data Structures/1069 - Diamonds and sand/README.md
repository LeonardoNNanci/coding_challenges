# Diamonds and sand

### [Problem descriiption](https://www.beecrowd.com.br/judge/en/problems/view/1069)

Use a stack to keep track of '<' characters. Push when '<' and pop when '>'.

Since the stack only stores '<', it can be replaced by a counter representing the size of the stack. Incrementing by one when pushing and decrementing by one when popping.

Every time there's a '>', check if the stack is empty. If not, increment the complete diamonds counter and pop from the stack.

After the input string is processed, print the counter.