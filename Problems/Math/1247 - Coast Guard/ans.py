from math import sqrt

while True:
    try:
        d, vf, vg = map(float, input().split())
        tg = sqrt(d**2 + 12**2) / vg
        tf = 12 / vf
        print("N") if tg > tf else print("S")
    except EOFError:
        break
