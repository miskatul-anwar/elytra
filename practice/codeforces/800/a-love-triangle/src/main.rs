use std::io::{stdin, stdout, BufWriter, Write};

fn main() {
    let mut input = String::new();
    stdin().read_line(&mut input).unwrap();
    let n: usize = input.trim().parse().unwrap();

    let mut f = vec![0; n + 1]; // Plane likes mapping
    input.clear();
    stdin().read_line(&mut input).unwrap();
    let likes: Vec<usize> = input
        .trim()
        .split_whitespace()
        .map(|x| x.parse().unwrap())
        .collect();

    for i in 0..n {
        f[i + 1] = likes[i]; // Store mapping
    }

    let mut found = false;

    // Checking for a cycle of length 3
    for i in 1..=n {
        let a = f[i]; // Plane i likes a
        let b = f[a]; // Plane a likes b
        let c = f[b]; // Plane b likes c

        if c == i {
            // If plane c likes back to i, it's a triangle!
            found = true;
            break;
        }
    }

    let out = &mut BufWriter::new(stdout());
    if found {
        writeln!(out, "YES").unwrap();
    } else {
        writeln!(out, "NO").unwrap();
    }
}
