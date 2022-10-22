import sys
import random

print(sys.argv[1])
arrLen = int(sys.argv[1])
expSum = 0

rNums = random.randbytes(arrLen)

for i in rNums:
    n = 1 + (i % 4)
    expSum += n*n
    print(n, flush=False)

print(expSum)
print(sys.argv[2])
print(sys.argv[3])
