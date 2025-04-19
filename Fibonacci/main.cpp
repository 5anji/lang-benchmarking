#include <cstdint>
#include <iostream>

uint64_t fibonacci(uint64_t n) {
  if (n <= 1) {
    return n;
  }
  return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
  uint64_t const n = 40; // Change this to the desired position in the Fibonacci sequence
  std::cout << "Fibonacci(" << n << ") = " << fibonacci(n) << std::endl;
  return 0;
}
