avg = int(input())
done = int(input())

needed = 80 * (done + 1) - avg * done

if (needed > 100):
    print(-1)
elif (needed < 0):
    print(0)
else:
    print(needed)