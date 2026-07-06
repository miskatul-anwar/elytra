import sys
import threading

input = sys.stdin.readline
write = sys.stdout.write
N = 10**5 + 10
k = 0
dp = [-1] * N
h = [0] * N


def sol(n):
    if n == 0:
        return 0
    if dp[n] != -1:
        return dp[n]

    cost = 10**18 + 1
    for i in range(1, k + 1):
        if n - i >= 0:
            cost = min(cost, sol(n - i) + abs(h[n] - h[n - i]))
    dp[n] = cost
    return dp[n]


def main():
    global h, k
    n, k = map(int, input().split())
    h = list(map(int, input().split()))
    write(str(sol(n - 1)) + "\n")


if __name__ == "__main__":
    threading.Thread(target=main).start()
