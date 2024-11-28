package main

import "fmt"

func fibonacci(n uint64) uint64 {
	if n <= 1 {
		return n
	}
	return fibonacci(n-1) + fibonacci(n-2)
}

func main() {
	const n uint64 = 30 // Change this to the desired position in the Fibonacci sequence
	fmt.Printf("Fibonacci(%d) = %d\n", n, fibonacci(n))
}
