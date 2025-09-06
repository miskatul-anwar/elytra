#![allow(unused)]
use std::io::{BufWriter, Stdout, Write, stdin, stdout};

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

    let k: usize = scan.next();
    let a: usize = scan.next();
    let b: usize = scan.next();
    let s: String = scan.next();
    let n: usize = s.len();
    let mut l = 0;

    if n % k == 0 {
        l = n / k
    } else {
        l = n / (k + 1)
    }

    if l > b {
        writeln!(out, "NO solution").unwrap()
    } else {
        let mut i: usize = 0;
        let mut j: usize = 0;

        while j < k {
            writeln!(out, "{}", &s[i..=i + l]).unwrap();
            i += l;
            j += 1
        }
    }
}
