def comp(item):
    return (-len(item),)


for i in range(int(input())):
    words = input().split()
    words.sort(key=comp)
    print(str(words)[1:-1].replace(",", "").replace("'", ""))
