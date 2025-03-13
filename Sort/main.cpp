#include <iostream>
#include <algorithm>
#include <array>
#include <cstdint>

int main() {
    std::array<uint32_t, 500000> arr;

    for (size_t i = 0; i < arr.size(); ++i) {
        arr[i] = (500000 - i) % 251;
    }

    std::sort(arr.begin(), arr.end());

    return 0;
}
