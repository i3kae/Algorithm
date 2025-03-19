t = int(input())
for test in range(t):
    totalTime = 0
    N = int(input())
    S, T = map(int, input().split())
    while N != 0:
        if (N % 2 == 1):
            totalTime += S
            N -= 1
        elif (N // 2 * S < T):
            totalTime += N // 2 * S;
            N //= 2
        else:
            totalTime += T
            N //= 2

    print(totalTime)