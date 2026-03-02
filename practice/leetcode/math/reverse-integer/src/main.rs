#![allow(unused)]

pub fn reverse(mut x: i32) -> i32 {
    let mut result = 0i64;

    while x != 0 {
        let pop = x as i64 % 10;
        x /= 10;
        result = result * 10 + pop;
    }

    if result > i32::MAX as i64 || result < i32::MIN as i64 {
        0
    } else {
        result as i32
    }
}
fn main() {
    println!("Hello, world!");
}
