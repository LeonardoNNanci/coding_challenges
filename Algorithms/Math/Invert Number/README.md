# Invert Number - O(n)

Invert the order of the digits.

1. Get the last digit with __x % 10__;
2. Append that digit to the response with __inv * 10 + last_digit__;
3. Remove the last digit from the original number with __x / 10__
4. Repeat these steps until __x == 0__