# Huaauhahhuahau

### [Problem description](https://www.beecrowd.com.br/judge/en/problems/view/2242).

### Solution

Check if the vowels in the string form a palindrome.

Use a set of vowels to check if the current character is a vowel.

In Python, created a new string containing only the vowels from the input, reversed it and compared if it is equal the non-reversed one.

In C++, searched for vowels by index. One index controller move from the beggining to the right, and another, from the end to the left. When each of them finds a vowel, check if they are equal. Stop the procedure when the index controler moving right is greater than the one moving left.