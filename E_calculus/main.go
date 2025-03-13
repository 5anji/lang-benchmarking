package main

import (
    "fmt"
)

func computeE(terms int) float64 {
    e := 1.0
    factorial := 1.0

    for i := 1; i <= terms; i++ {
        factorial *= float64(i)
        e += 1.0 / factorial
    }

    return e
}

func main() {
    // terms := 20
    terms := 40
    // terms := 20
    result := computeE(terms)
    fmt.Printf("e ≈ %.15f\n", result)
}
