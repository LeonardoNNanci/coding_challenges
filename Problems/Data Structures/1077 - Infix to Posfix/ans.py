from collections import deque


def isVar(c):
    return ("a" <= c <= "z") or ("A" <= c <= "Z") or ("0" <= c <= "9")


def priority(c):
    if c == "+":
        return 0
    if c == "-":
        return 0
    if c == "*":
        return 1
    if c == "/":
        return 1
    return 2


stack = deque()
n = int(input())
for _ in range(n):
    equation = input()

    for c in equation:
        if isVar(c):
            print(c, end="")

        # push to the stack
        elif c == "(":
            stack.append("(")

        # pop from stack until '('
        elif c == ")":
            while stack[-1] != "(":
                print(stack.pop(), end="")
            stack.pop()

        # pop from stack until lower priority
        else:
            while stack and stack[-1] != "(" and priority(c) <= priority(stack[-1]):
                print(stack.pop(), end="")
            stack.append(c)

    while stack:
        print(stack.pop(), end="")

    print()
