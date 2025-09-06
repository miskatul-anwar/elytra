#![allow(unused)]
use std::io::{stdin, stdout, BufWriter, Stdout, Write};

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

fn is_prime(x: i32) -> bool {
    if x <= 1 {
        return false;
    }
    for i in 2..=(x as f64).sqrt() as i32 {
        if x % i == 0 {
            return false;
        }
    }
    true
}

fn solve(scan: &mut Scanner, out: &mut BufWriter<Stdout>) {
    let mut x: i32 = scan.next();
    let k: i32 = scan.next();

    if k > 1 && x > 1 {
        writeln!(out, "NO").unwrap()
    } else if k == 1 {
        if is_prime(x) {
            writeln!(out, "YES").unwrap()
        } else {
            writeln!(out, "NO").unwrap()
        }
    } else {
        if k == 2 {
            writeln!(out, "YES").unwrap()
        } else {
            writeln!(out, "NO").unwrap()
        }
    }
}

fn main() {
    let mut scan = Scanner::default();
    let out = &mut BufWriter::new(stdout());

    let mut t: usize = scan.next();

    loop {
        if t == 0 {
            break;
        }

        solve(&mut scan, out);
        t -= 1
    }
}
