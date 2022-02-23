for _ in range(int(input())):
    products = dict()

    for _ in range(int(input())):
        item, price = input().split()
        products[item] = float(price)

    total = 0
    for _ in range(int(input())):
        item, quant = input().split()
        total += products.get(item) * int(quant)

    print(f"R$ {total:0.2f}")
