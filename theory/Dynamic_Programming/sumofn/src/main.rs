#![allow(unused)]
use std::io::{stdin, stdout, BufWriter, Write};

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
pub fn f(n: i32) -> i32 {
    match n {
        0 => 0,
        1 => 1,
        _ => n + f(n - 1),
    }
}

pub fn main() {
    let mut sc = Scanner::default();
    let out = &mut BufWriter::new(stdout());

    let n: i32 = sc.next();
    writeln!(out, "{}", f(n)).unwrap();
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn tc01() {
        assert_eq!(f(0), 0);
    }
    #[test]
    fn tc02() {
        assert_eq!(f(1), 1);
    }
    #[test]
    fn tc03() {
        assert_eq!(f(5), 15);
    }
}
