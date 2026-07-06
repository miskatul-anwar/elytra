#![allow(unused)]

pub fn multiply(num1: String, num2: String) -> String {
    // TODO: Implement the multiplication logic here
    let n1 = num1.parse::<i128>().unwrap();
    let n2 = num2.parse::<i128>().unwrap();
    let product = n1 * n2;
    product.to_string()
}
fn main() {
    println!("Hello, world!");
}
