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
    let s: String = scan.next();
    let n: usize = s.len();

    if n > 10 {
        writeln!(
            out,
            "{}{}{}",
            s.chars().nth(0).unwrap(),
            n - 2,
            s.chars().nth(n - 1).unwrap()
        )
        .unwrap()
    } else {
        writeln!(out, "{}", s).unwrap()
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
