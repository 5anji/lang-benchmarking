fn fibonacci(n: u64) -> u64 {
    if n <= 1 {
        return n;
    }
    fibonacci(n - 1) + fibonacci(n - 2)
}

fn main() {
    let n = 30; // Change this to the desired position in the Fibonacci sequence
    println!("Fibonacci({}) = {}", n, fibonacci(n));
}
