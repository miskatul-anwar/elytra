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

    let s: String = sc.next();
    let t: String = sc.next();

    let s_chars: Vec<char> = s.chars().collect();
    let t_chars: Vec<char> = t.chars().collect();

    let mut i = 0;
    let mut j = 0;
    let mut ans: i64 = 0;

    while i < s_chars.len() || j < t_chars.len() {
        let mut s_count = 0;
        let mut t_count = 0;

        while i < s_chars.len() && s_chars[i] == 'A' {
            s_count += 1;
            i += 1;
        }
        while j < t_chars.len() && t_chars[j] == 'A' {
            t_count += 1;
            j += 1;
        }

        ans += (s_count as i64 - t_count as i64).abs();

        if i < s_chars.len() && j < t_chars.len() {
            if s_chars[i] != t_chars[j] {
                writeln!(out, "-1").unwrap();
                return;
            }
            i += 1;
            j += 1;
        } else if i < s_chars.len() || j < t_chars.len() {
            writeln!(out, "-1").unwrap();
            return;
        }
    }

    writeln!(out, "{}", ans).unwrap();
}
