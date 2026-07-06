import sys
import threading

sys.setrecursionlimit(10**6)

input = sys.stdin.readline
write = sys.stdout.write

N = 10**5 + 10

dp = [-1] * N
h = [0] * N


def func(i):
    if i == 0:
        return 0
    if dp[i] != -1:
        return dp[i]
    cost = 10**9

    cost = min(cost, func(i - 1) + abs(h[i] - h[i - 1]))
    if i > 1:
        cost = min(cost, func(i - 2) + abs(h[i] - h[i - 2]))

    dp[i] = cost
    return dp[i]


def main():
    global h

    n = int(input())
    h_values = list(map(int, input().split()))

    for i in range(n):
        h[i] = h_values[i]

    write(str(func(n - 1)) + "\n")


if __name__ == "__main__":
    threading.Thread(target=main).start()
