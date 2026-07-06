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

    let t: usize = sc.next();
    for _ in 1..=t {
        let n: usize = sc.next();
        let mut cnt = 0;

        for i in 1..=n {
            let p_i: usize = sc.next();
            if p_i <= i {
                cnt += 1;
            }
        }

        writeln!(out, "{}", cnt).unwrap()
    }
}
