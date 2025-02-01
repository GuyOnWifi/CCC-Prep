# L dmoj

def ban(n):
    global b
    if len(n) > 1:
        if n[0] == "B":
            b += 1
            return ban(n[1:])
        elif n[0] == "A":
            return ban(n[1:])
        elif n[0] == "N":
            return(ban(n[1:]))
        elif n[0] == "S":
            if b > 0:
                b-= 1
            if n[1] == "N":
                return ban(n[2:])
            else:
                return False
        else:
            return False
    elif n == "A" and b == 0:
        return True
    elif n == "" and b == 0:
        return True
    elif n == "S" and b == 1:
        return True
    else:
        return False
e = input()
while not e=="X":
    b = 0
    if ban(e):
        print("YES")
    else:
        print("NO")
    e = input()