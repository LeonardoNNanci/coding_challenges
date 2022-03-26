c = int(input())
for _ in range(c):
    n, *grades = map(int, input().split())
    avg = sum(grades) / n
    count = 0
    for grade in grades:
        count += grade > avg
    print(f"{count*100/n:0.3f}%")
