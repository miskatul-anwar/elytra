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
    let k: usize = scan.next();
    let l: Vec<i64> = (0..n).map(|_| scan.next()).collect();
    let r: Vec<i64> = (0..n).map(|_| scan.next()).collect();
    let mut m = vec![0i64; n];
    let mut sum_max: i64 = 0;

    for i in 0..n {
        m[i] = l[i].min(r[i]);
        sum_max += l[i].max(r[i]);
    }

    m.sort_unstable_by(|a, b| b.cmp(a));

    let mut sum_m = 0;
    for i in 0..k - 1 {
        sum_m += m[i]
    }

    writeln!(out, "{}", sum_max + sum_m + 1).unwrap()
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
