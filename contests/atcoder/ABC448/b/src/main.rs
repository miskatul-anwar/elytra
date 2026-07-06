#![allow(unused)]
use std::{
    cmp::min,
    io::{BufWriter, Write, stdin, stdout},
};

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
    let mut sc = Scanner::default();
    let out = &mut BufWriter::new(stdout());

    let (n, m) = (sc.next::<usize>(), sc.next::<usize>());
    let c = (0..m).map(|_| sc.next::<i64>()).collect::<Vec<_>>();
    let mut sum_b = vec![0i64; m];

    for _ in 0..n {
        let a = sc.next::<usize>();
        let b = sc.next::<i64>();
        sum_b[a - 1] += b;
    }

    let mut ans = 0i64;

    for i in 0..m {
        ans += min(sum_b[i], c[i]);
    }

    writeln!(out, "{}", ans).unwrap()
}
