#![allow(unused)]
use std::io::{BufWriter, Write, stdin, stdout};

#[derive(Default)]
struct Scanner {
    buffer: Vec<String>,
}

impl Scanner {
    fn next<T: std::str::FromStr>(&mut self) -> T {
        loop {
            if let Some(token) = self.buffer.pop() {
                return token.parse().ok().expect("Failed parse");
            }
            let mut input = String::new();
            stdin().read_line(&mut input).expect("Failed read");
            self.buffer = input.split_whitespace().rev().map(String::from).collect();
        }
    }
}

/*~~~~~~~~~~~~~*
 * CODE BELOW: *
 *~~~~~~~~~~~~~*/
/// Computes the Greatest Common Divisor (GCD) of two integers `a` and `b`
/// using the Extended Euclidean Algorithm.
///
/// It also finds integers `x` and `y` such that:
///
/// ```
/// a * x + b * y = gcd(a, b)
/// ```
///
/// # Arguments
///
/// * `a` - An integer (can be positive or negative)
/// * `b` - An integer (can be positive or negative)
///
/// # Returns
///
/// A tuple `(gcd, x, y)`:
/// - `gcd`: the greatest common divisor of `a` and `b`
/// - `x`, `y`: Bézout coefficients such that `a*x + b*y = gcd`
///
/// # Example
///
/// ```
/// let a = 35;
/// let b = 15;
/// let (gcd, x, y) = extended_gcd(a, b);
/// assert_eq!(gcd, 5);
/// assert_eq!(a * x + b * y, gcd);
/// println!("GCD: {}, x: {}, y: {}", gcd, x, y);
/// ```
pub fn extended_gcd(a: i64, b: i64) -> (i64, i64, i64) {
    if a == 0 {
        return (b, 0, 1);
    }

    let (gcd, x1, y1) = extended_gcd(b % a, a);

    let x = y1 - (b / a) * x1;
    let y = x1;

    (gcd, x, y)
}
fn main() {
    let mut sc = Scanner::default();
    let out = &mut BufWriter::new(stdout());
}
