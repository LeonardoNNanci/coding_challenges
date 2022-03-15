def invert(x):
    inv = 0
    while x > 0:
        last_digit = x % 10
        inv = (inv * 10) + last_digit
        x //= 10
    return inv
