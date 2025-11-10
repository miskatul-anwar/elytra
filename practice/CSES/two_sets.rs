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

fn sol(n: i64) {
    let total_sum = n * (n + 1) / 2;
    if total_sum % 2 != 0 {
        println!("NO")
    } else {
        println!("YES");

        let mut half = total_sum / 2;
        let mut v1 = Vec::new();
        let mut v2 = Vec::new();

        for i in (1..=n).rev() {
            if half - i >= 0 {
                half -= i;
                v1.push(i);
            } else {
                v2.push(i);
            }
        }

        println!("{}", v1.len());
        v1.iter().for_each(|i| print!("{i} "));
        println!();
        println!("{}", v2.len());
        v2.iter().for_each(|i| print!("{i} "));
        println!();
    }
}

fn main() {
    let mut sc = Scanner::default();
    let n: i64 = sc.next();
    sol(n);
}
