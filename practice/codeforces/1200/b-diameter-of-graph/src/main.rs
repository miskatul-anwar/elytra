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

fn solve(scan: &mut Scanner, out: &mut BufWriter<Stdout>) {
    let n: i64 = scan.next();
    let m: i64 = scan.next();
    let k: i64 = scan.next();

    if (n - 1i64) * n >> 1 < m || m < n - 1 {
        writeln!(out, "NO").unwrap();
        return;
    }

    if n == 1 {
        if k > 1 {
            writeln!(out, "YES").unwrap()
        } else {
            writeln!(out, "NO").unwrap()
        }
    } else if m < (n - 1i64) * n >> 1 {
        if k > 3 {
            writeln!(out, "YES").unwrap()
        } else {
            writeln!(out, "NO").unwrap()
        }
    } else if k > 2 {
        writeln!(out, "YES").unwrap()
    } else {
        writeln!(out, "NO").unwrap()
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
