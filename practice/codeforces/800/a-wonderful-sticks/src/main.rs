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
    let s: Vec<char> = scan.next::<String>().chars().collect();
    let sz = s.len();
    let mut v: Vec<i32> = vec![0; n];

    let mut l = 1;
    let mut r = n as i32;

    for i in (0..n - 1).rev() {
        if s[i] == '<' {
            v[i + 1] = l;
            l += 1
        } else {
            v[i + 1] = r;
            r -= 1
        }
    }

    v[0] = l;

    for i in v {
        write!(out, "{} ", i).unwrap()
    }

    writeln!(out).unwrap()
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
