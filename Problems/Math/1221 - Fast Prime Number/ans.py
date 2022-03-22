from math import sqrt


c = int(input())
for _ in range(c):
    x = int(input())

    if x < 2:
        print("Not Prime")

    elif x == 2:
        print("Prime")

    else:
        prime = True
        bound = int(sqrt(x)) + 1
        for i in range(3, bound, 2):
            prime = x % i != 0
            if not prime:
                break
        print("Prime") if prime else print("Not Prime")
