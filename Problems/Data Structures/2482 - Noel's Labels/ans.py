labels = dict()

n = int(input())
for _ in range(n):
    language = input()
    label = input()
    labels[language] = label

m = int(input())
for _ in range(m):
    name  = input()
    language = input()
    print(name)
    print(labels[language], end="\n\n")
