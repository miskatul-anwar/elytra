#![allow(unused)]
use std::{
    fmt::write,
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

/*~~~~~~~~~~~~~*
 * CODE BELOW: *
 *~~~~~~~~~~~~~*/

fn main() {
    let mut sc = Scanner::default();
    let out = &mut BufWriter::new(stdout());

    let h: usize = sc.next();
    let w: usize = sc.next();

    for i in 0..h {
        for j in 0..w {
            let mut cnt = 0;

            if i > 0 {
                cnt += 1
            }

            if i < h - 1 {
                cnt += 1
            }

            if j > 0 {
                cnt += 1
            }

            if j < w - 1 {
                cnt += 1
            }

            if j > 0 {
                write!(out, " ").expect("Failed write");
            }

            write!(out, "{}", cnt).expect("Failed write");
        }

        writeln!(out).expect("Failed write");
    }

    out.flush().expect("Failed flush");
}
