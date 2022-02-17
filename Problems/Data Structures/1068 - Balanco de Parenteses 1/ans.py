from sys import stdin

for eq in stdin:
    stack = 0
    for c in eq[:-1]:
        if c == "(":
            stack += 1
        elif c == ")":
            stack -= 1

        if stack < 0:
            break

    if stack != 0:
        print("incorrect")
    else:
        print("correct")
