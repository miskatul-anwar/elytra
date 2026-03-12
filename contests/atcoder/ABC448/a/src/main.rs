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

    let n = sc.next();
    let mut x = sc.next();
    let mut a = Vec::new();
    for _ in 0..n {
        a.push(sc.next::<i32>());
    }

    for i in a.iter() {
        if *i < x {
            writeln!(out, "{}", 1).unwrap();
            x = *i;
        } else {
            writeln!(out, "{}", 0).unwrap()
        }
    }
}
