N = int(input())
cnt = 0
for i in range(N):
    S = input()
    if S[0] == 'C':
        cnt += 1
print(cnt)