C = int(input())
for _ in range(C):
    text = input()
    mid = len(text) // 2
    print(text[:mid][::-1] + text[mid:][::-1])
