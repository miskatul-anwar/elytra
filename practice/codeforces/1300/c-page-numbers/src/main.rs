#![allow(unused)]
use std::{
    collections::BTreeSet,
    io::{stdin, stdout, BufWriter, Write},
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

    let nums: Vec<u32> = scan
        .next::<String>()
        .trim()
        .split(',')
        .map(|s| s.parse().unwrap())
        .collect::<BTreeSet<_>>() // sort and dedup
        .into_iter()
        .collect();

    let mut output = String::new();
    let mut i = 0;

    while i < nums.len() {
        let start = nums[i];
        let mut end = start;

        while i + 1 < nums.len() && nums[i + 1] == nums[i] + 1 {
            i += 1;
            end = nums[i];
        }

        if start == end {
            output.push_str(&format!("{},", start));
        } else {
            output.push_str(&format!("{}-{},", start, end));
        }

        i += 1;
    }

    output.pop(); // remove last comma
    writeln!(out, "{}", output).unwrap();
}
