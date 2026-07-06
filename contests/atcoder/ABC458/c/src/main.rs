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
    let n: usize = s.len();
    let mut res: usize = 0;

    for (i, c) in s.chars().enumerate() {
        if c == 'C' {
            let left = i;
            let right = n - 1 - i;
            let radius = left.min(right);
            res += radius + 1;
        }
    }

    writeln!(out, "{}", res).unwrap();
}
