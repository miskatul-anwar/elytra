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
macro_rules! gcd {
    ($a:expr, $b:expr) => {{
        let (mut a, mut b) = ($a, $b);
        while b != 0 {
            let temp = b;
            b = a % b;
            a = temp;
        }
        a
    }};
}

fn euler_totient(mut n: i32) -> i32 {
    let mut result = n;
    let mut factor = 2;
    while factor * factor <= n {
        if n % factor == 0 {
            while n % factor == 0 {
                n /= factor;
            }
            result -= result / factor;
        }
        factor += 1;
    }
    if n > 1 {
        result -= result / n;
    }
    result
}

fn mod_exp(mut base: i32, mut exponent: i32, modulus: i32) -> i32 {
    let mut result = 1;
    base %= modulus;
    while exponent > 0 {
        if exponent % 2 == 1 {
            result = (result * base) % modulus;
        }
        base = (base * base) % modulus;
        exponent /= 2;
    }
    result
}

fn main() {
    let mut scanner = Scanner::default();
    let out = &mut BufWriter::new(stdout());

    let a = scanner.next::<i32>();
    let k = scanner.next::<i32>();
    let n = scanner.next::<i32>();

    if gcd!(a, n) != 1 {
        writeln!(
            out,
            "a and n are not coprime, Euler's theorem does not apply."
        )
        .unwrap();
    } else {
        let totient = euler_totient(n);
        let reduced_exponent = k % totient;
        let result = mod_exp(a, reduced_exponent, n);

        writeln!(out, "Euler's Totient φ({}) = {}", n, totient).unwrap();
        writeln!(out, "Reduced exponent (k mod φ(n)) = {}", reduced_exponent).unwrap();
        writeln!(
            out,
            "Result: {}^{} ≡ {} (mod {})",
            a, reduced_exponent, result, n
        )
        .unwrap();
    }
}
