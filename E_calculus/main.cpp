#include <iostream>
#include <stdfloat>

std::float64_t compute_e(int terms) {
    std::float64_t e = 1.0;
    std::float64_t factorial = 1.0;

    for (int i = 1; i <= terms; ++i) {
        factorial *= i;
        e += 1.0 / factorial;
    }

    return e;
}

int main() {
    // int terms = 20;
    int terms = 40;
    // int terms = 20;
    std::float64_t result = compute_e(terms);
    std::cout << "e ≈ " << result << std::endl;
    return 0;
}
