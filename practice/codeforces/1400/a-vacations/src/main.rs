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

fn main() {
    let mut scan = Scanner::default();
    let out = &mut BufWriter::new(stdout());

    let n: usize = scan.next();
    let mut a: Vec<usize> = (0..n).map(|_| scan.next()).collect();
    let mut r: usize = 0;

    if a[0] == 0 {
        r += 1
    }

    for i in 1..n {
        if a[i] == 0 {
            r += 1
        } else if a[i] == 1 && a[i - 1] == 1 {
            a[i] = 0;
            r += 1
        } else if a[i] == 2 && a[i - 1] == 2 {
            a[i] = 0;
            r += 1
        } else {
            if a[i - 1] == 1 {
                a[i] = 2
            } else if a[i - 1] == 2 {
                a[i] = 1
            }
        }
    }

    writeln!(out, "{}", r).unwrap()
}
