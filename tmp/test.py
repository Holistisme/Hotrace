import random
import string

N = 40000
M = 10000
Q_KEEP = True

def randstr():
    return ''.join(random.choices(string.ascii_letters + string.digits, k=16))

keep_keys = []

with open("hotrace_test.txt", "w") as f:
    for i in range(N):
        key = randstr()
        value = randstr()
        f.write(key + "\n")
        f.write(value + "\n")

        if Q_KEEP and (i % 8 == 0):
            keep_keys.append(key)

    f.write("\n")

    for _ in range(M):
        f.write(randstr() + "\n")

    for key in keep_keys:
        f.write(key + "\n")
