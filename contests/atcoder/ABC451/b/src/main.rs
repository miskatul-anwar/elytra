#![allow(unused)]
use std::io::{BufWriter, Write, stdin, stdout};

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

/*~~~~~~~~~~~~~*
 * CODE BELOW: *
 *~~~~~~~~~~~~~*/

fn main() {
    let mut sc = Scanner::default();
    let out = &mut BufWriter::new(stdout());

    let n: usize = sc.next();
    let m: usize = sc.next();

    let mut cnt_a = vec![0; m];
    let mut cnt_b = vec![0; m];

    for _ in 0..n {
        let ai: usize = sc.next();
        let bi: usize = sc.next();
        cnt_a[ai - 1] += 1;
        cnt_b[bi - 1] += 1;
    }

    for i in 0..m {
        writeln!(out, "{}", cnt_b[i] - cnt_a[i]).unwrap()
    }
}
