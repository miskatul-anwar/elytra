#![allow(unused)]
use std::io::{stdin, stdout, BufWriter, Stdout, Write};

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

fn main() {
    let mut scan = Scanner::default();
    let out = &mut BufWriter::new(stdout());

    let raw: String = scan.next();
    let s1: String = raw.replace("dot", ".");
    let s2: String = s1.replace("at", "@");
    let mut email = String::new();

    let mut at = 0;

    for i in 0..s2.len() {
        if i == s2.len() - 1 || i == 0 {
            if s2.chars().nth(i).unwrap() == '@' {
                email.push_str("at");
            } else if s2.chars().nth(i).unwrap() == '.' {
                email.push_str("dot");
            } else {
                email.push(s2.chars().nth(i).unwrap());
            }
        } else if s2.chars().nth(i).unwrap() == '@' {
            if at > 0 {
                email.push_str("at");
            } else {
                email.push_str("@");
                at += 1
            }
        } else {
            email.push(s2.chars().nth(i).unwrap());
        }
    }

    writeln!(out, "{}", email).unwrap()
}
