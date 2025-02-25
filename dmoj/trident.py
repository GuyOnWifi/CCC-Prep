t = int(input())
s = int(input())
h = int(input())

for i in range(t):
    print("*" + " " * s + "*" + " " * s + "*")

l = (2 * s + 3)
print("*" * l)

l2 = l // 2

for i in range(h):
    print(" " * l2 + "*")
