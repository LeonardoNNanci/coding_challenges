c = int(input())
for _ in range(c):
    n = int(input())
    sum = 0
    for i in range(n):
        text = input()
        for j, ch in enumerate(text):
            sum += ord(ch) - ord("A") + i + j
    print(sum)
