#![allow(unused)]
use std::{
    collections::HashMap,
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

    let mut t = sc.next::<String>();

    let mut map = HashMap::new();

    for c in t.chars() {
        *map.entry(c).or_insert(0) += 1;
    }

    let max_count = map.values().max().unwrap_or(&0);

    let mut max_chars = Vec::new();

    for (&c, &count) in &map {
        if count == *max_count {
            max_chars.push(c);
        }
    }

    for c in &max_chars {
        t = t.replace(*c, "");
    }

    writeln!(out, "{}", t).unwrap();
}
