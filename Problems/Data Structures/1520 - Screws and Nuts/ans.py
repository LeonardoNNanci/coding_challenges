while True:
    try:
        arr = [0] * 105
        n = int(input())
        for i in range(n):
            x, y = map(int, input().split())
            for j in range(x, y + 1):
                arr[j] += 1

        acc = 0
        num = int(input())
        for i in range(num):
            acc += arr[i]
        if arr[num] > 0:
            print(f"{num} found from {acc} to {acc + arr[num]-1}")
        else:
            print(f"{num} not found")

    except EOFError:
        break
    except:
        continue
