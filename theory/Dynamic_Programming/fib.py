import sys
import threading

input = sys.stdin.readline
write = sys.stdout.write

sys.setrecursionlimit(10**5)
dp = [-1] * 10**5


def fib(n):
    if n == 1 or n == 0:
        return n
    if dp[n] != -1:
        return dp[n]
    dp[n] = fib(n - 1) + fib(n - 2)
    return dp[n]


def main():
    n = int(input())
    print(fib(n))


if __name__ == "__main__":
    threading.Thread(target=main).start()
