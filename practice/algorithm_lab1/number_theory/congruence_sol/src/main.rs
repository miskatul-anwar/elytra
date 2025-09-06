#![allow(unused)]
//! A small CLI utility to solve linear congruences of the form `a * x ≡ b (mod m)`.
//!
//! This program reads `a`, `b`, and `m` from standard input and prints either that no
//! solution exists or a canonical solution `x0` modulo the reduced modulus `m/g`,
//! where `g = gcd(a, m)`.
//!
//! It uses the Extended Euclidean Algorithm to compute modular inverses.
//!
//! Example
//! - For input: `14 30 100`
//!   - We reduce by `g = gcd(14, 100) = 2` to get `7x ≡ 15 (mod 50)`
//!   - The modular inverse of `7 (mod 50)` is `43`
//!   - One solution is `x ≡ 15 * 43 ≡ 45 (mod 50)`
//!
//! See `solve_congruence` for a programmatic API.

use std::io::{BufWriter, Write, stdin, stdout};

/// A simple token scanner for reading CLI input.
///
/// This is provided by the prompt and used as-is to parse values from stdin.
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

/// Compute the Extended Euclidean Algorithm for integers `a` and `b`.
///
/// Returns a triple `(g, x, y)` where:
/// - `g` is `gcd(a, b)` (always non-negative),
/// - `x` and `y` satisfy the Bezout identity: `a*x + b*y = g`.
///
/// Properties:
/// - If `g = 1`, then `x` is the modular inverse of `a` modulo `b` (when `b > 0`) i.e. `a*x ≡ 1 (mod b)`.
/// - More generally, when `g = gcd(a, b)`, if `g | c`, then solutions to `a*z ≡ c (mod b)` exist.
///
/// Examples:
/// - `extended_gcd(30, 12)` returns `(6, 1, -2)` because `30*1 + 12*(-2) = 6`.
fn extended_gcd(a: i64, b: i64) -> (i64, i64, i64) {
    if b == 0 {
        // Ensure g >= 0 to make downstream reasoning consistent.
        if a >= 0 { (a, 1, 0) } else { (-a, -1, 0) }
    } else {
        let (g, x1, y1) = extended_gcd(b, a % b);
        let x = y1;
        let y = x1 - (a / b) * y1;
        (g, x, y)
    }
}

/// Solve the linear congruence `a * x ≡ b (mod m)`.
///
/// This returns either:
/// - `Ok((x0, m_reduced))`, where:
///   - `g = gcd(a, m)`
///   - `m_reduced = m / g` (always positive)
///   - `x0` is the smallest non-negative solution modulo `m_reduced`
/// - or `Err("No solution exists")` if `g` does not divide `b`.
///
/// Notes:
/// - If a solution exists, there are exactly `g` distinct residue classes modulo `m`,
///   and the solution set is `x ≡ x0 (mod m_reduced)`.
/// - Internally, this uses the fact that if `g = gcd(a, m)` and `g | b`, then
///   `a' * x ≡ b' (mod m')` with `a' = a/g`, `b' = b/g`, `m' = m/g`, and the inverse
///   of `a'` modulo `m'` can be derived from the Bezout coefficients of `(a, m)`.
///
/// Examples:
/// ```rust
/// let (x0, m1) = solve_congruence(14, 30, 100).unwrap();
/// assert_eq!(m1, 50);
/// assert_eq!(x0, 45); // 14*45 = 630 ≡ 30 (mod 100)
///
/// // No solution example: 6x ≡ 4 (mod 8) has solutions, but 6x ≡ 5 (mod 8) doesn't.
/// assert!(solve_congruence(6, 5, 8).is_err());
/// ```
fn solve_congruence(a: i64, b: i64, m: i64) -> Result<(i64, i64), &'static str> {
    if m == 0 {
        return Err("Modulus m must be non-zero");
    }
    let mut a = a;
    let mut b = b;
    let mut m = m.abs(); // Work with positive modulus

    let (g, x, _y) = extended_gcd(a, m);

    if b % g != 0 {
        return Err("No solution exists");
    }

    // Reduce by gcd
    a /= g;
    b /= g;
    m /= g;

    // x from extended_gcd(a_original, m_original) satisfies a_orig*x + m_orig*y = g
    // => (a_orig/g)*x ≡ 1 (mod m_orig/g) -> x is an inverse of a' modulo m'
    let inv = ((x % m) + m) % m;

    // Compute solution x0 = b' * inv mod m'
    let x0 = {
        let prod = (b as i128) * (inv as i128);
        let m128 = m as i128;
        let r = ((prod % m128) + m128) % m128;
        r as i64
    };

    Ok((x0, m))
}

fn main() {
    let mut scan = Scanner::default();
    let mut out = BufWriter::new(stdout());

    writeln!(out, "Enter a, b, m for equation a*x ≡ b (mod m): ").ok();

    let a: i64 = scan.next();
    let b: i64 = scan.next();
    let m: i64 = scan.next();

    match solve_congruence(a, b, m) {
        Ok((x0, m_reduced)) => {
            writeln!(out, "Solution of x:{}", x0).ok();
            writeln!(out, "One solution: x ≡ {} (mod {})", x0, m_reduced).ok();
        }
        Err(msg) => {
            writeln!(out, "{}", msg).ok();
        }
    }
}
