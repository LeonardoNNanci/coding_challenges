def GCD(a, b):
    return a if b == 0 else GCD(b, a % b)


def soma(n1, d1, n2, d2):
    return [(n1 * d2 + n2 * d1), (d1 * d2)]


def sub(n1, d1, n2, d2):
    return [(n1 * d2 - n2 * d1), (d1 * d2)]


def mult(n1, d1, n2, d2):
    return [(n1 * n2), (d1 * d2)]


def div(n1, d1, n2, d2):
    return [(n1 * d2), (n2 * d1)]


ops = {"+": soma, "-": sub, "*": mult, "/": div}

n = int(input())

while n > 0:
    equacao = list(input().split())
    res = ops[equacao[3]](
        int(equacao[0]), int(equacao[2]), int(equacao[4]), int(equacao[6])
    )
    divisor = GCD(res[0], res[1])
    print("{}/{} = {}/{}".format(res[0], res[1], res[0] // divisor, res[1] // divisor))
    n -= 1
