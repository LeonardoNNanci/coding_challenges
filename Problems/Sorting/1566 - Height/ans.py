import sys
import io, os

input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

NC = int(input().decode())
for _ in range(NC):
    n = int(input().decode())
    cs = [0] * 240

    for h in map(int, input().decode().split()):
        cs[h] += 1

    not_first = False
    for i in range(231):
        for j in range(cs[i]):
            if not_first:
                sys.stdout.write(" " + str(i))
            else:
                sys.stdout.write(str(n))
                not_first = True
    sys.stdout.write("\n")
