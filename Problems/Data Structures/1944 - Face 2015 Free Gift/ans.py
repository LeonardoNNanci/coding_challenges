from collections import deque

n = int(input())
panel = deque("FACE")
temp = deque()
new_letters = deque()

winners = 0
for _ in range(n):
    count = 0
    letters = input().split()
    for ch in letters:
        if ch == panel[-1]:
            temp.append(panel.pop())
            count += 1
        new_letters.append(ch)

    if count == 4:
        winners += 1
        while temp:
            temp.pop()
        while new_letters:
            new_letters.popleft()

    else:
        while temp:
            panel.append(temp.pop())
        while new_letters:
            panel.append(new_letters.popleft())

    if not panel:
        panel = deque("FACE")

print(winners)
