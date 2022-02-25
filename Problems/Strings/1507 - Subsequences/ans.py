n = int(input())
for _ in range(n):
    s = input()
    q = int(input())
    for _ in range(q):
        r = input()
        count = 0
        for ch in s:
            if ch == r[count]:
                count += 1
                if count == len(r):
                    break

        if count == len(r):
            print("Yes")
        else:
            print("No")
