even, odd = [], []
for i in range(int(input())):
    a = int(input())
    if a % 2:  #  Se for ímpar
        odd.append(a)
    else:
        even.append(a)
even.sort()
odd.sort(reverse=True)
numbers = even + odd
print(str(numbers)[1:-1].replace(", ", "\n"))
