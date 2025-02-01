def tp(a, b):
    la = len(a)
    lb = len(b)
    lao = len(a[0])
    lbo = len(b[0])
    result = [[0] * lao *lbo for i in range(la* lb)]
    for ra in range(la):
        for ca in range(lao):
            for rb in range(lb):
                for cb in range(lbo):
                    result[ra *lb + rb][ca *lbo+cb] = a[ra][ca]* b[rb][cb] 
    return result
#yay ??

n = int(input())
product =[]
for bruh in range(n):
    r, c =map(int, input().split())
    matrix= []
    for i in range(r):
        row =list(map(int, input().split()))
        matrix.append(row)
    if bruh == 0:
        product = matrix
    else:
        product = tp(product, matrix)
        
mxv = -2147483647
miv = 2147483647
mxr =-2147483647
mir= 2147483647
mxc = -2147483647
mic= 2147483647
# UH 2147483647 MAYBE
for i in range(len(product)):
    rows=sum(product[i])
    mxv = max(mxv, max(product[i]))
    miv = min(miv, min(product[i]))
    mxr= max(mxr, rows)
    mir = min(mir, rows)

for j in range(len(product[0])):
    cols = 0
    for i in range(len(product)):
        cols += product[i][j]
    mxc = max(mxc, cols)
    mic = min(mic, cols)
    
print(mxv)
print(miv)
print(mxr)
print(mir)
print(mxc)
print(mic)