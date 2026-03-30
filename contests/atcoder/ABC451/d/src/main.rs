#![allow(unused)]
use std::{
    collections::BTreeSet,
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
fn solve(sc: &mut Scanner) -> u64 {
    let n: usize = sc.next();
    let limit: u64 = 1_000_000_000;

    let mut gdints = BTreeSet::new();
    let mut pws_f_2 = Vec::new();

    let mut p: u64 = 1;
    while p <= limit {
        pws_f_2.push(p.to_string());
        gdints.insert(p);
        if let Some(next_p) = p.checked_mul(2) {
            p = next_p;
        } else {
            break;
        }
    }

    let mut curr_g: Vec<String> = pws_f_2.clone();

    for _ in 0..10 {
        let mut nxt_g = Vec::new();
        for existing in &curr_g {
            for p2 in &pws_f_2 {
                let mut combined = existing.clone();
                combined.push_str(p2);

                if let Ok(val) = combined.parse::<u64>() {
                    if val <= limit {
                        if gdints.insert(val) {
                            nxt_g.push(combined);
                        }
                    }
                }
            }
        }
        if nxt_g.is_empty() {
            break;
        }
        curr_g = nxt_g;
    }

    *gdints.iter().nth(n - 1).unwrap()
}

fn main() {
    let mut sc = Scanner::default();
    let out = &mut BufWriter::new(stdout());

    let result = solve(&mut sc);

    writeln!(out, "{}", result).unwrap();
}
