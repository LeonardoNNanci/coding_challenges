from collections import deque

n = int(input())
while n:
    a = input().split()
    b = input().split()
    A, B, station = deque(a), deque(b), deque()

    while A or station:
        if A and A[0] == B[0]:
            print("IR", end="")
            A.popleft()
            B.popleft()
        elif station and station[-1] == B[0]:
            print("R", end="")
            station.pop()
            B.popleft()
        elif A:
            print("I", end="")
            station.append(A.popleft())

        if not A and station and station[-1] != B[0]:
            print(" Impossible", end="")
            break

    print()
    n = int(input())
