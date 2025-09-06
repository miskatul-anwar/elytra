package main

import "fmt"

type ll = int64

const mod ll = 10 ^ 5

func pow(n, exp ll) ll {
	res := ll(1)

	for ; exp > 0; exp /= 2 {
		if exp%2 == 1 {
			res = (res * n) % mod
		}

		n = (n * n) % mod
	}

	return res
}

func main() {
	var n, exp ll

	fmt.Scanf("%d %d", &n, &exp)

	res := pow(n, exp)

	fmt.Println(res)
}
