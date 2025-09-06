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

fn is_alpha(c: char) -> bool {
    c.is_ascii_alphabetic()
}

fn main() {
    let mut scan = Scanner::default();
    let out = &mut BufWriter::new(stdout());

    let n: usize = scan.next();
    let s: String = scan.next();
    let s = s.chars().collect::<Vec<_>>();

    let mut count = 0;
    let mut pcount = 0;
    let mut np = vec![0];
    let mut bracket = false;

    for i in 0..n {
        if s[i] == '(' {
            bracket = true;
        }

        if !bracket {
            if is_alpha(s[i]) && (i + 1 == n || s[i + 1] == '_' || s[i + 1] == '(') {
                count += 1;
                np.push(count);
                count = 0;
                continue;
            } else if is_alpha(s[i]) && i + 1 < n && s[i + 1] != '_' {
                count += 1;
            } else if is_alpha(s[i]) && i == n - 1 {
                count += 1;
                np.push(count);
            }
        } else {
            if is_alpha(s[i]) && i + 1 < n && s[i + 1] == '_' {
                pcount += 1;
            } else if is_alpha(s[i]) && i + 1 < n && s[i + 1] == ')' {
                pcount += 1;
                bracket = false;
            }
        }

        if i + 1 < n && s[i + 1] == ')' {
            bracket = false;
        }
    }

    let max_np = *np.iter().max().unwrap_or(&0);
    writeln!(out, "{} {}", max_np, pcount).unwrap();
}
