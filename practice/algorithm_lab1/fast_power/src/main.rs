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

fn multiplicative_order(base: i64, m: i64) -> i64 {
    let gcd = gcd!(base, m);

    if gcd != 1 {
        return -1;
    }

    for exp in 1..m {
        if power(base, exp, m) == 1 {
            return exp;
        }
    }

    -1
}

fn power(base: i64, mut exp: i64, m: i64) -> i64 {
    let mut result: i64 = 1;
    let mut base = base % m;

    while exp > 0 {
        if exp % 2 != 0 {
            result = (result * base) % m;
        }

        base = (base * base) % m;
        exp /= 2;
    }

    return result;
}

fn main() {
    let mut sc = Scanner::default();
    let out = &mut BufWriter::new(stdout());

    let base = sc.next();
    let exp = sc.next();
    let m = sc.next();
    let result = power(base, exp, m);
    let order = multiplicative_order(base, m);

    writeln!(out, "{}", result).unwrap();
    writeln!(out, "{}", order).unwrap();
}
