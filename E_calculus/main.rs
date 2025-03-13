fn compute_e(terms: u32) -> f64 {
    let mut e = 1.0;
    let mut factorial = 1.0;

    for i in 1..=terms {
        factorial *= i as f64;
        e += 1.0 / factorial;
    }

    e
}

fn main() {
    // let terms = 20;
    let terms = 40;
    // let terms = 20;
    let result = compute_e(terms);
    println!("e ≈ {}", result);
}
