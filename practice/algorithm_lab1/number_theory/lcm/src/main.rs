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

macro_rules! lcm {
    ($a:expr, $b:expr) => {
        ($a * $b) / gcd!($a, $b)
    };
}

fn main() {
    let mut sc = Scanner::default();
    let out = &mut BufWriter::new(stdout());

    let a: i32 = sc.next();
    let b: i32 = sc.next();

    writeln!(out, "{}", lcm!(a, b)).unwrap()
}
