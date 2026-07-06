import sys
import threading

sys.setrecursionlimit(1_000_000)

N = 10**5 + 1
dp = [-1] * N


def fib(n):
    if n == 0:
        return 0
    if n == 1:
        return 1
    if dp[n] != -1:
        return dp[n]
    dp[n] = fib(n - 1) + fib(n - 2)
    return dp[n]


def main():
    n = int(input())
    print(fib(n))


if __name__ == "__main__":
    threading.Thread(target=main).start()
