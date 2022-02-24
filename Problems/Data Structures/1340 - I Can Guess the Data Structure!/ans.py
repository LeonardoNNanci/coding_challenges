from collections import deque
from heapq import *

while True:
    try:
        isPq, isSt, isQ = True, True, True
        pq, st, q = [], deque(), deque()

        n = int(input())
        for _ in range(n):
            command, x = map(int, input().split())

            if command == 1:
                heappush(pq, -x)
                st.append(x)
                q.append(x)

            else:
                if x != -heappop(pq):
                    isPq = False
                if x != st.pop():
                    isSt = False
                if x != q.popleft():
                    isQ = False

        if not (isPq or isSt or isQ):
            print("impossible")
        elif isPq and not (isSt or isQ):
            print("priority queue")
        elif isSt and not (isPq or isQ):
            print("stack")
        elif isQ and not (isPq or isSt):
            print("queue")
        else:
            print("not sure")


    except EOFError:
        break
        