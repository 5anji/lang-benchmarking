package main

import (
    "sort"
)

func main() {
    arr := make([]uint32, 500000)
    for i := 0; i < 500000; i++ {
        arr[i] = uint32((500000 - i) % 251)
    }

    sort.Slice(arr, func(i, j int) bool {
        return arr[i] < arr[j]
    })
}
