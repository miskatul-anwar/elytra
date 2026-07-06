#![allow(unused)]
use std::cmp::Reverse;
use std::collections::BinaryHeap;
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
    let mut trees: BinaryHeap<Reverse<u64>> = BinaryHeap::new();

    for _ in 1..=t {
        let q: i32 = sc.next();
        let n: u64 = sc.next();

        match q {
            1 => {
                trees.push(Reverse(n));
            }
            2 => {
                while let Some(&Reverse(min_h)) = trees.peek() {
                    if min_h <= n {
                        trees.pop();
                    } else {
                        break;
                    }
                }
            }
            _ => {}
        }

        writeln!(out, "{}", trees.len()).unwrap();
    }
}
