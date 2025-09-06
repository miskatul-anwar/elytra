use std::{i32, io::stdin};

fn main() {
    let mut input = String::new();
    stdin().read_line(&mut input).unwrap();
    let mut iter = input
        .trim()
        .split_whitespace()
        .map(|i| i.parse::<_>().unwrap());

    let a: i32 = iter.next().unwrap();
    let b: i32 = iter.next().unwrap();

    println!("{}", a + b)
}
