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

    let mut ans = 0;

    let n: usize = sc.next();
    let k: usize = sc.next();
    let arr: Vec<i32> = (0..n).map(|_| sc.next()).collect();

    for i in 0..n {
        if arr[i] >= arr[k - 1] && arr[i] > 0 {
            ans += 1
        }
    }

    writeln!(out, "{ans}").unwrap()
}
