#![allow(unused)]
use std::{
    collections::HashMap,
    io::{stdin, stdout, BufWriter, Stdout, Write},
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

fn main() {
    let mut scan = Scanner::default();
    let out = &mut BufWriter::new(stdout());

    let mut n: usize = scan.next();
    let mut odds: Vec<usize> = Vec::new();
    let mut evens: Vec<usize> = Vec::new();

    for i in 1..=n {
        let tmp: usize = scan.next();

        if tmp % 2 == 0 {
            evens.push(i);
        } else {
            odds.push(i);
        }
    }

    if evens.len() < odds.len() {
        writeln!(out, "{}", evens[0]).unwrap()
    } else {
        writeln!(out, "{}", odds[0]).unwrap()
    }
}
