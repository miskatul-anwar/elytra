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

    let mut t: usize = scan.next();
    let mut ans = 0;

    ans = loop {
        if t == 0 {
            break ans;
        }

        let (a, b, c) = (scan.next::<i32>(), scan.next::<i32>(), scan.next::<i32>());

        if a == 1 && b == 1 || b == 1 && c == 1 || a == 1 && c == 1 {
            ans += 1
        }

        t -= 1
    };

    writeln!(out, "{}", ans).unwrap()
}
