use std::{
    io::{BufWriter, Write, stdin, stdout},
    usize,
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
    let mut sc = Scanner::default();
    let out = &mut BufWriter::new(stdout());

    let n: usize = sc.next();
    let k: usize = sc.next();
    let mut arr: Vec<usize> = (0..n).map(|_| sc.next()).collect();

    // Check if n is divisible by k
    if n % k != 0 {
        writeln!(out, "NO").unwrap();
        return;
    }

    let grps = n / k;
    let tot_sum: usize = arr.iter().sum();

    // Check if the total sum can be divided into groups evenly
    if tot_sum % grps != 0 {
        writeln!(out, "NO").unwrap();
        return;
    }

    let target_sum = tot_sum / grps;

    // Try redistributing the elements
    arr.sort_unstable();
    let mut groups = vec![Vec::new(); grps];
    let mut group_sums = vec![0; grps];

    for &val in arr.iter().rev() {
        let mut placed = false;
        for i in 0..grps {
            if group_sums[i] + val <= target_sum {
                group_sums[i] += val;
                groups[i].push(val);
                placed = true;
                break;
            }
        }
        if !placed {
            writeln!(out, "NO").unwrap();
            return;
        }
    }

    // Ensure all groups have the target sum
    if group_sums.iter().all(|&sum| sum == target_sum) {
        writeln!(out, "YES").unwrap();
        for group in groups {
            writeln!(out, "{:?}", group).unwrap();
        }
    } else {
        writeln!(out, "NO").unwrap();
    }
}
