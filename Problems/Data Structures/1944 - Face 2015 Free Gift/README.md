# Face 2015 Free Gift

### [Problem description](https://www.beecrowd.com.br/judge/en/problems/view/1944).

### Solution

Use stacks to store the panel and the letters that from the panel that match the new ones. Use queue to represent the new letters as they are presented.

Always store the new letter in a queue.

If the top of the panel matches the new letter, store it in a temporary stack.

If the all 4 new letters match the top of the panel, increment a winner and empty the helper structures.
Otherwise, pop the temporary stack and the new letters queue into the panel.

If the panel is ever empty at the end of an iteration, push "FACE" to it.
