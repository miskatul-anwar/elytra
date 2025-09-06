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
    let n: usize = scan.next();
    let s: Vec<char> = scan.next::<String>().trim().chars().collect();

    let mut m = 0;
    let mut c01 = 0;
    let mut c10 = 0;
    let mut prev = '0';

    let mut i: usize = 0;
    loop {
        if i == n {
            break;
        }

        let curr: char = s[i];

        if curr != prev {
            m += 1;

            if prev == '0' {
                c01 += 1
            } else {
                c10 += 1
            }

            prev = curr
        }

        i += 1
    }

    let mut best_gain = 0;

    if c01 >= 2 || c10 >= 2 {
        best_gain = 2
    } else if m >= 2 {
        best_gain = 1
    } else {
        best_gain = 0
    }

    let m_prime = m - best_gain;

    writeln!(out, "{}", n + m_prime).unwrap()
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
