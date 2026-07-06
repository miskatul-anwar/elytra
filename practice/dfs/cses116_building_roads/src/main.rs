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

    let n: usize = sc.next();
    let m: usize = sc.next();

    let mut mat: Vec<Vec<usize>> = vec![vec![0; n + 1]; n + 1];
    let mut visited: Vec<Vec<usize>> = vec![vec![0; n + 1]; n + 1];

    for _ in 0..m {
        let a: usize = sc.next();
        let b: usize = sc.next();
        mat[a][b] = 1;
        mat[b][a] = 1;
    }

    let mut cnt = 0;
    let mut ans = Vec::new();

    for i in 1..=n {
        for j in 1..=n {
            if mat[i][j] == 0 && visited[i][j] == 0 && visited[j][i] == 0 && i != j {
                visited[i][j] = 1;
                visited[j][i] = 1;
                ans.push((i, j));
                cnt += 1
            }
        }
    }

    println!("{}", cnt);
    for e in ans.into_iter() {
        println!("{} {}", e.0, e.1)
    }
}
