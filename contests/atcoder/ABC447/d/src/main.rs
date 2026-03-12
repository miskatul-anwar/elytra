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

    let mut s: String = sc.next();
    let mut n: i32 = 0;

    let a_indices = s.match_indices('A').map(|(i, _)| i).collect::<Vec<_>>();
    let b_indices = s.match_indices('B').map(|(i, _)| i).collect::<Vec<_>>();
    let c_indices = s.match_indices('C').map(|(i, _)| i).collect::<Vec<_>>();

    let mut count = 0;
    let mut b_ptr = 0;
    let mut c_ptr = 0;

    for a_pos in &a_indices {
        while b_ptr < b_indices.len() && b_indices[b_ptr] < *a_pos {
            b_ptr += 1;
        }

        if b_ptr < b_indices.len() {
            let b_pos = b_indices[b_ptr];
            while c_ptr < c_indices.len() && c_indices[c_ptr] < b_pos {
                c_ptr += 1;
            }

            if c_ptr < c_indices.len() {
                count += 1;
                b_ptr += 1;
                c_ptr += 1;
            }
        }
    }

    writeln!(out, "{}", count).unwrap();
}
