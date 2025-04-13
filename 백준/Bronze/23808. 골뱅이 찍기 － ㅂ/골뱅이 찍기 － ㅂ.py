def f(N):
    result = ['' for _ in range(N * 5)]
    
    for idx in range(N*5):
        if 2 * N - 1  < idx < 2 * N + N or idx >= N * 5 - N:
            result[idx] = "@" * (N * 5)
        else:
            result[idx] = f"{'@' * N}{' ' * (N * 5 - N * 2)}{'@' * N}"
        
    return "\n".join(result)


N = int(input())
print(f(N))